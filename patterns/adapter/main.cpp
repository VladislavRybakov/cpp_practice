#include "BaloonAdapter.h"

int main()
{
  Target* target = new BaloonAdapter(5, 10, 2);
  std::cout << target->Passport() << "\n";
  target->ModifyVolume(3);
  std::cout << target->Passport() << "\n";
  target->ModifyVolume(-5);
  std::cout << target->Passport() << "\n";
}