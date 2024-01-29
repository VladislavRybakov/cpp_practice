#pragma once
#include "iostream"

class Target
{
public:
  virtual void ModifyVolume(const double& dV) = 0;
  virtual double GetDp(const int& T0, const int& T1) const = 0;
  virtual std::string Passport() = 0;
};