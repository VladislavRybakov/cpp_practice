#pragma once
#include <iostream>
#include "Telephone.h"

class State // Blocked -> Expectation -> Call -> Talk; Talk -> Expectation; Call -> Expectation; Talk -> Blocked
{
  std::string name;
public:
  State(const std::string& name) : name(name) {}
  virtual void call(Telephone* telephone) = 0;
  virtual void answer(Telephone*) = 0;
  virtual void endcall(Telephone*) = 0;
  virtual void balanceplus(Telephone* telephone, int plus) = 0;
  std::string getname() {
    return name;
  }
};

class Expectation : public State
{
public:
  Expectation() : State("Expectation") {}
   void call(Telephone* telephone) {
    std::cout << "Beep... Do a call...\n";
    telephone->SetState(new Expectation);
  }
  virtual void answer(Telephone* telephone) {
    std::cout << "Ring-ring! Answer the call.\n";

  }
  virtual void endcall(Telephone* telephone) {
    std::cout << "You can not end the call. You aren't talking now.\n";
  }
  virtual void balanceplus(Telephone* telephone, int plus) {
    telephone->balanceplus(plus);
  }
};

class Call : public State
{
public:
  Call() : State("Call") {}
  virtual void call(Telephone* telephone) {
    std::cout << "The call in process, you can't do another one.\n";
  }
  virtual void answer(Telephone* telephone) {
    std::cout << "Incoming call canceled. Keep calling.\n";
  }
  virtual void endcall(Telephone* telephone) {
    std::cout << "End call.\n";
  }
  virtual void balanceplus(Telephone* telephone, int plus) {
    std::cout << "The call in process. You can't change your balance now.\n";
  }
};

class Talk : public State
{
public:
  Talk() : State("Talk") {}
  virtual void call(Telephone* telephone) {
    std::cout << "The talk in process, you can't do another one.\n";
  }
  virtual void answer(Telephone* telephone) {
    std::cout << "Incoming call canceled. Keep Talking.\n";
  }
  virtual void endcall(Telephone* telephone) {
    std::cout << "End call.\n";
  }
  virtual void balanceplus(Telephone* telephone, int plus) {
    std::cout << "The talk in process. You can't change your balance now.\n";
  }
};

class Blocked : public State
{
public:
  Blocked() : State("Blocked") {}
  virtual void call(Telephone* telephone) {
    std::cout << "You can't do a call, top up your balance.\n";
  }
  virtual void answer(Telephone* telephone) {
    std::cout << "Ring-ring! Answer the call.\n";
  }
  virtual void endcall(Telephone* telephone) {
    std::cout << "End call.\n";
  }
  virtual void balanceplus(Telephone* telephone, int plus) {
    telephone->balanceplus(plus);
    telephone->SetState(new Expectation());
  }
};