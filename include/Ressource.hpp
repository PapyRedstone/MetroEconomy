#pragma once

#include <array>

namespace RessourceType{
  enum Type{
    Wood,
    Food
  };
  const std::array<Type, 2> All = {Wood, Food}; 
}

class Ressource{
public:
  Ressource(RessourceType::Type t);

  RessourceType::Type getType();
  int getAmount();
  void addAmount(int n);
  void addAmountPerSecond(int a);
  void update();

private:
  RessourceType::Type type;
  int amount;
  int amountPerSecond;
};
