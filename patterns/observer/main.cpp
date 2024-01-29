#include <iostream>
#include <list>
using namespace std;

class Subject;
class Observer;
class Oil;

class Subject
{
public:
  virtual void registerObserver(Observer& one) = 0;
  virtual void removeObserver(Observer& one) = 0;
  virtual void notifyObservers(double cost) = 0;
  virtual void setCost(double cost_) = 0;
};

class Observer
{
public:
  virtual void update(double cost) = 0;
};

class RubleExchangeRate : public Observer
{
  Subject* oil;
public:
  double rate;
  void update(double cost) {
    rate = cost;
    display();
  }
  void subscribe(Subject& subj) {
    cout << "Now Ruble is an observer!" << endl;
    oil = &subj;
    subj.registerObserver(*this);
  }
  void unsubscribe(Subject& subj) {
    cout << "Ruble is NOT observer now.\n";
    subj.removeObserver(*this);
    oil = NULL;
  }
  void rateUp(double plus) {
    rate += plus;
  }
  void rateDown(double plus) {
    rate -= plus;
  }
  void display() {
    cout << "Ruble exchange rate " << rate << endl;
  }
};

class GazpromShares : public Observer
{
  Subject* oil;
public:
  double sharesCost;
  void update(double cost) {
    sharesCost = cost;
    display();
  }
  void subscribe(Subject& subj) {
    cout << "Now Gazprom is an observer!" << endl;
    oil = &subj;
    subj.registerObserver(*this);
  }
  void unsubscribe(Subject& subj) {
    cout << "Gazprom is NOT observer now.\n";
    subj.removeObserver(*this);
    oil = NULL;
  }
  void costUp(double plus) {
    sharesCost += plus;
  }
  void costDown(double plus) {
    sharesCost -= plus;
  }
  void display() {
    cout << "Gazprom shares Cost: " << sharesCost << endl;
  }
};

class Oil : public Subject
{
  list<Observer*> observers;
public:
  double cost;
  Oil() = default;
  void registerObserver(Observer& one) {
    observers.push_front(&one);
  }
  void removeObserver(Observer& one) {
    observers.remove(&one);
  }
  void notifyObservers(double cost) {
    for (auto& Observer: observers) {
      Observer->update(cost);
    }
  }
  void setCost(double cost_) {
    cost = cost_;
    notifyObservers(cost);
  }
  ~Oil() {
    observers.clear();
  }
  void costUp(double plus) {
    cost += plus;
    notifyObservers(cost);
  }
  void costDown(double plus) {
    cost -= plus;
    notifyObservers(cost);
  }
};


int main()
{
  Oil oil;
  RubleExchangeRate rate;
  GazpromShares gazprom;
  rate.subscribe(oil);
  gazprom.subscribe(oil);
  oil.setCost(100);
  gazprom.unsubscribe(oil);
  oil.costUp(2);
}