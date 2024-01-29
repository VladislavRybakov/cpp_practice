#pragma once
#include "States.h"

class Telephone
{
private:
  State* state;
  int number, balance, probability;
public:
  Telephone() : balance(0) {
    state = new Blocked;
  }
  void call() {
    state->call(this);
  }
  void answer() {
    state->answer(this);
  }
  void endcall() {
    state->endcall(this);
  }
  void balanceplus(int plus) {
    balance += plus;
  }
  void SetState(State* s)
  {
    std::cout << "Chaging state from " << state->getname() << " to " << s->getname() << "..." << std::endl;
    delete state;
    state = s;
  }
  ~Telephone() {
    delete state;
  }
};