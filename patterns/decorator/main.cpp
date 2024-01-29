#include <iostream>
using namespace std;

// Предметная область - кафе с дессертами
class Dessert
{
protected:
  string name;
public:
  Dessert() : name("Dessert") {}
  virtual string getName() { return name; }
  virtual void printDessert() {
    cout << name;
  }
  virtual double cost() = 0;
  virtual ~Dessert() {
    cout << "Dessert destructor.\n";
  }
};

class Donut : public Dessert
{
public:
  Donut() {
    name = "Donut";
  }
  double cost() {
    return 1.49;
  }
  ~Donut() {
    cout << "Donut destructor.\n";
  }
};

class IceCream : public Dessert
{
public:
  IceCream() {
    name = "Ice cream";
  }
  double cost() {
    return 0.99;
  }
};

class Topings : public Dessert
{
protected:
  Dessert* dessert_;
public:
  Topings() = default;
  virtual ~Topings() {
    delete dessert_;
     cout << "Topings destructor.\n";
  }
};

class Chocolate : public Topings
{
public:
  Chocolate(Dessert* dessert) {
    dessert_ = dessert;
  }
  void printDessert() {
    dessert_->printDessert();
    cout << " + Chocolate";
  }
  double cost() {
    return dessert_->cost() + 0.40;
  }
  ~Chocolate() {
    cout << "Chocolate destructor.\n";
  }
};

class Powder : public Topings
{
public:
  Powder(Dessert* dessert) {
    dessert_ = dessert;
  }
  void printDessert() {
    dessert_->printDessert();
    cout << " + Powder";
  }
  double cost() {
    return dessert_->cost() + 0.25;
  }
  ~Powder() {
    cout << "Powder destructor.\n";
  }
};

class Syrup : public Topings
{
public:
  Syrup(Dessert* dessert) {
    dessert_ = dessert;
  }
  void printDessert() {
    dessert_->printDessert();
    cout << " + Syrup";
  }
  double cost() {
    return dessert_->cost() + 0.15;
  }
  ~Syrup() {
    cout << "Syrup destructor.\n";
  }
};

int main()
{
  Dessert* one = new Donut();
  one = new Chocolate(one);
  one = new Powder(one);
  one->printDessert();
  cout << " cost " << one->cost() << endl << endl;
  delete one;
  one = new Powder(new Syrup(new Chocolate(new IceCream())));
  cout << endl;
  one->printDessert();
  cout << " cost " << one->cost() << "\n\n";
  delete one;
}