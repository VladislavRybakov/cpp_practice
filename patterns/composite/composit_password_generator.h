#pragma once
#include "individual_generators.h"
#include <vector>

std::string randomswap(std::string str) {
  int first = rand() % (str.length()), second = rand() % (str.length());
  char tmp = str[first];
  str[first] = str[second];
  str[second] = tmp;
  return str;
}

class Composit_password_generator : public Password_generator
{
private:
  std::vector<Password_generator*> generators;
public:
  void add(Password_generator *one) {
    generators.push_back(one);
  }
  std::string generate(int letters_numbers, int digit_number, int symbols_number) override {
    std::string password = "", check;
    for (Password_generator *i : generators) {
      check = i->allowed_chars();
      if (check[0] == 'a') password += i->generate(letters_numbers);
      if (check[0] == '0') password += i->generate(digit_number);
      if (check[0] == '~') password += i->generate(symbols_number);
    }
    for (int i = 0; i < password.length() * password.length(); i++) {
      password = randomswap(password);
    }
    return password;
  }
};
