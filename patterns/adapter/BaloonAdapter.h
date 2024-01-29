#pragma once
#include "Baloon.h"
#include "Target.h"

class BaloonAdapter : public Baloon, public Target
{
public:
  BaloonAdapter() = default;
  BaloonAdapter(const double& v, const double& m, const double& M) : Baloon(v, m, M) {}

  void ModifyVolume(const double& dV) override {
    volume += dV;
  }

  double GetDp(const int& T0, const int& T1) const override {
    return GetPressure(T0) - GetPressure(T1);
  }

  std::string Passport() override {
    return ToString();
  }
};