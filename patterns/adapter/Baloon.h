#pragma once
#include <iostream>
#include <string>

class Baloon
{
protected:
  double volume;
  double mass;
  double Molar;
public:
  Baloon() = default;
  Baloon(const double& v, const double& m, const double& M) {
    volume = v;
    mass = m;
    Molar = M;
  }

  double GetPressure(const int& T) const {
    return AmontOfMatter() * 8.31 * (double)T / volume;
  }

  double AmontOfMatter() const {
    return mass / Molar;
  }

  std::string ToString() const {
    std::string s = "[Volume = ";
    s += std::to_string(volume);
    s += " m^3 ; Gas mass = ";
    s += std::to_string(mass);
    s += " kg ; Molar mass = ";
    s += std::to_string(Molar);
    s += " kg/mol]";
    return s;
  }
};