#include <iostream>
#include <thread>
#include <vector>

void print(std::string& s) {
  std::cout << std::this_thread::get_id() << " " << s << std::endl;
}

int main() {
  std::string str = "asddfghhjjjlk;;";

  std::thread t(print, std::ref(str));

  t.join();

  std::cout << std::thread::hardware_concurrency();

  int n = std::thread::hardware_concurrency();
  std::vector<std::thread> thread_vec(n);
  for (int i = 0; i < n-1; i++) {
    thread_vec[i] = std::thread(print, std::ref(str));
  }
  for (int i = 0; i < n; i++) {
    thread_vec[i].join();
  }

  //    print(str);
}