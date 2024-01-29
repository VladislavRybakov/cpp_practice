#pragma once
#include <iostream>
using namespace std;

class FlyBehavior
{
public:
  virtual void fly() {
    cout << "Idk how to fly.\n";
  }
};

class FlyWithWings : public FlyBehavior
{
public:
  void fly() {
    cout << "Always wanna fly!\n";
  }
};

class FlyNoWay : public FlyBehavior
{
public:
  void fly() {
    cout << "I can't fly!\n";
  }
};

class QuackBehaivor
{
public:
  virtual void quack() {
    cout << "Idk how to quack.\n";
  }
};

class Quack : public QuackBehaivor
{
public:
  void quack() {
    cout << "QUA QUA QUA\n";
  }
};

class Squeak : public QuackBehaivor
{
public:
  void quack() {
    cout << "PI PI PI\n";
  }
};

class MuteQuack : public QuackBehaivor
{
public:
  void quack() {
    cout << "................silence................\n";
  }
};

class Duck
{
protected:
  FlyBehavior* flyBehavior;
  QuackBehaivor* quackBehavior;
public:
  Duck() {
    flyBehavior = new FlyBehavior;
    quackBehavior = new QuackBehaivor;
  }
  void swim() {
    cout << "SWIM SWIM SWIM!\n";
  }
  virtual void display() {
    cout << "Who I am?\n";
  }
  void performQuack() { quackBehavior->quack(); }
  void performFly() { flyBehavior->fly(); }
  virtual void setFlyBehavior() = 0;
  virtual void setQuackBehavior() = 0;
  ~Duck() {
    delete flyBehavior, quackBehavior;
  }
};

class MallardDuck : public Duck
{
public:
  void display(){
    cout << "I am MallardDuck!";
  }
  void setFlyBehavior() {
    flyBehavior = new FlyWithWings;
  }
  void setQuackBehavior() {
    quackBehavior = new Quack;
  }
};

class RedheadDuck : public Duck
{
public:
  void display() {
    cout << "I am RedheadDuck!";
  }
  void setFlyBehavior() {
    flyBehavior = new FlyNoWay;
  }
  void setQuackBehavior() {
    quackBehavior = new Quack;
  }
};

class RubberDuck : public Duck
{
public:
  void display() {
    cout << "I am RubberDuck!";
  }
  void setFlyBehavior() {
    flyBehavior = new FlyNoWay;
  }
  void setQuackBehavior() {
    quackBehavior = new Squeak;
  }
};

class DecoyDuck : public Duck
{
public:
  void display() {
    cout << "I am DecoyDuck!";
  }
  void setFlyBehavior() {
    flyBehavior = new FlyNoWay;
  }
  void setQuackBehavior() {
    quackBehavior = new MuteQuack;
  }
};