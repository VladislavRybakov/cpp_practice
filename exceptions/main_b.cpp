#include <iostream>

class MyException : public std::exception
{
public:
  MyException(const char* error) : exception(error) { this->error = error; }
  std::string error_msg() const { return error; }
private:
  std::string error;
};

int div_(int a, int b) {
  if (b == 0) throw MyException("Error with code 0: division by 0.\n");
  return a / b;
}

int main()
{
  int a, b;
  std::cout << "Enter two numbers: ";
  while (std::cin >> a >> b) {
    try {
      std::cout << "Result: " << div_(a, b) << std::endl;
      std::cout << "Enter two numbers: ";
    }
    catch (const MyException& e) {
      std::cout << "Process failed. " << e.error_msg();
      std::cout << "Enter two numbers: ";
    }
  }
}