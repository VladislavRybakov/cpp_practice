#include "composit_password_generator.h"

int main()
{
  Digit_generator dig;
  Letter_generator let;
  Symbol_generator sym;
  Composit_password_generator passwordgenerator;
  std::string password;
  std::cout << "Enter the minimum password length: ";
  int n, len, letters_num, digit_num, ans;
  std::cin >> n;
  if (n < 0) {
    std::cout << "Wrong enter!\n";
    return 0;
  }
  passwordgenerator.setlength(n);
  len = passwordgenerator.length();
  std::cout << "Do you like to enter some rules?\n 0) No\n 1) Yes\nYour choice (just number): ";
  std::cin >> n;
  srand(time(0));
  switch (n){
  case 0:
    passwordgenerator.add(&let);
    passwordgenerator.add(&sym);
    passwordgenerator.add(&dig);
    letters_num = rand() % (len + 1);
    digit_num = rand() % (len + 1 - letters_num);
    password = passwordgenerator.generate(letters_num, digit_num, len - digit_num - letters_num); // рандомное кол-во букв, цифр и символов
    break;
  case 1:
    std::cout << "\nDo you want letters in password?\n 0) No\n 1) Yes\nYour choice (just number): ";
    std::cin >> ans;
    if (ans == 0) {
      std::cout << "\nDo you want digitals in password?\n 0) No\n 1) Yes\nYour choice (just number): ";
      std::cin >> ans;
      if (ans == 0) {
        passwordgenerator.add(&sym);
        password = passwordgenerator.generate(0, 0, len);
      }
      else {
        passwordgenerator.add(&dig);
        std::cout << "How many digitals you want?\nEnter the number: ";
        std::cin >> n;
        if (n > len) {
          if (n <= len * 2) {
            password = passwordgenerator.generate(0, n, 0);
          }
          else {
            password = passwordgenerator.generate(0, len, 0);
          }
        }
        else {
          passwordgenerator.add(&sym);
          password = passwordgenerator.generate(0, n, len - n);
        }
      }
    }
    else {
      passwordgenerator.add(&let);
      std::cout << "How many letters you want?\nEnter the number: ";
      std::cin >> n;
      if (n > 2 * len) {
        password = passwordgenerator.generate(len, 0, 0);
      }
      else {
        std::cout << "\nDo you want digitals in password?\n 0) No\n 1) Yes\nYour choice (just number): ";
        std::cin >> ans;
        if (ans == 0) {
          passwordgenerator.add(&sym);
          password = passwordgenerator.generate(n, 0, len - n);
        }
        else {
          passwordgenerator.add(&dig);
          passwordgenerator.add(&sym);
          std::cout << "How many digitals you want?\nEnter the number: ";
          std::cin >> ans;
          if (ans > len) {
            password = passwordgenerator.generate(n, 0, len - n);
          }
          else {
            password = passwordgenerator.generate(ans, n, len - n - ans);
          }
        }
      }
    }
    break;
  default:
    std::cout << "Wrong enter!\n";
    return 0;
  }
  std::cout << "\nYour password: " << password << '\n';
}