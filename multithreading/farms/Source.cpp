#include <iostream>
#include <mutex>
#include <condition_variable>
#include <future>
#include <thread>

class Character
{
  int balance;
  int farm;
  mutable std::mutex mute;
public:
  Character(int balance, int farm) : balance(balance), farm(farm) { }

  friend void earn_money(Character&);
  friend void build_farm(Character&);
};

std::condition_variable data_cond; //условная переменная

void earn_money(Character& a)
{
  while (a.farm < 5)
  {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::lock_guard<std::mutex> lk(a.mute);
    a.balance += 1;
    std::cout << "balance: " << a.balance << std::endl;
    if (a.balance >= 15) {
      data_cond.notify_one();
    }
  }
}

void build_farm(Character& a)
{
  while (a.farm < 5)
  {
    std::unique_lock<std::mutex> lk(a.mute);
    if (a.balance < 15) {
      data_cond.wait(lk);
    }
    lk.unlock();
    a.balance -= 15;
    std::cout << "start build a farm...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(60000));
    std::cout << "farm is built!\n";
    std::unique_lock<std::mutex> tk(a.mute);
    a.farm += 1;
    std::cout << "balance: " << a.balance << "\tfarm: " << a.farm << std::endl;
  }
}

void achieve() {
  Character a(0, 0);

  std::thread t1(earn_money, std::ref(a));
  std::thread t2(build_farm, std::ref(a));

  t1.join();
  t2.join();
}

int main()
{
  achieve();
}