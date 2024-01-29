#pragma once
#include "password_generator.h"

class Digit_generator : public Password_generator
{
public:
  std::string allowed_chars() {
    return "0123456789";
  }
};

class Symbol_generator : public Password_generator
{
public:
  std::string allowed_chars() {
    return "~!@#$%^&*()_-+=<>?/,.;:\'\"[]{}|";
  }
};

class Letter_generator : public Password_generator
{
public:
  std::string allowed_chars() {
    return "abcdefghijklmnopqrstuvwxyz";
  }
};