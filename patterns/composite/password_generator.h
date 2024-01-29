#pragma once
#include "iostream"
#include <ctime>

class Password_generator
{
private:
  int len;
public:
  virtual std::string generate(int letters_numbers, int digit_number, int symbols_number) { return ""; }
  virtual std::string generate(int number) {
    srand(time(0));
    std::string str = allowed_chars(), finalstr = "";
    for (int i = 0; i < number; i++) {
      finalstr += str[rand() % (str.length())];
    }
    return finalstr;
  }
  virtual int length() { return len; }
  void setlength(int n) {
    len = rand() % (n + 1) + n; // длина пароля рандомна, не меньше заданного числа и не превышает его более, чем в 2 раза
  }
  virtual std::string allowed_chars() { return ""; }
  virtual void add(Password_generator *one) {}
};

