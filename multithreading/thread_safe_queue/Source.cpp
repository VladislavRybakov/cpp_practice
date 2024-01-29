#include <mutex>
#include <thread>
#include <iostream>

class Account {
public:
  Account(int balance) : balance(balance) { }
  int getBalance() const {
    std::lock_guard<std::mutex> lock(m); // = m.lock()
    return balance; // критическая секция
  } // = m.unlock()
  bool withdraw(int amount) {
    std::lock_guard<std::mutex> lock(m);
    if (balance >= amount) {
      balance -= amount; // // критическая секция
      return true;
    }
    //std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    return false;
  }
  void deposit(int sum) {
    std::lock_guard<std::mutex> lock(m);
    balance += sum;
  }
private:
  int balance;
  mutable std::mutex m; //позволяет изменять данные в const контексте
};

void transfer(int clientid, Account& from, Account& to, int amount)
{
  std::mutex m;
  std::lock_guard<std::mutex> lock(m);
  if (from.withdraw(amount))
  {
    std::printf("Client %d withdraw %d OK\n", clientid, amount);
    to.deposit(amount);
    std::printf("Client %d deposit %d OK\n", clientid, amount);
  }
  else {
    std::printf("Client %d withdraw %d ERROR\n", clientid, amount);
  }
}

int main() {
  Account first(100), second(50);
  std::thread t1(transfer, 1, std::ref(first), std::ref(second), 50);
  std::thread t2(transfer, 2, std::ref(second), std::ref(first), 25);
  t1.join();
  t2.join();
  std::cout << "Account 1 balance " << first.getBalance() << "\n";
  std::cout << "Account 2 balance " << second.getBalance() << "\n";
  return 0;
}