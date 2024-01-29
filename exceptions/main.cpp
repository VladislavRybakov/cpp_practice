#include <iostream>

bool div_(int& a, int& b, int &ans) {
  if (b == 0) return 0;
  ans = a / b;
  return 1;
}

int main()
{
  int a, b, ans, istrue;
  std::cout << "Enter two numbers: ";
  while (std::cin >> a >> b) {
    istrue = div_(a, b, ans);
    if (istrue) {
      std::cout << "Result: " << ans << std::endl;
      std::cout << "Enter two numbers: ";
    }
    else {
      std::cout << "Process failed. Error with code 0: division by 0.\n";
      std::cout << "Enter two numbers: ";
    }
  }
}