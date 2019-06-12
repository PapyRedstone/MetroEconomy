#pragma once

#include <array>
#include <string>

typedef int ID;

namespace RessourceType{
  enum Type{
    Wood,
    Food
  };
  const std::array<Type, 2> All = {Wood, Food};
  const std::array<std::string, 2> StringType = {"Wood", "Food"};
}

class Ressource{
public:
  Ressource(RessourceType::Type t);

  RessourceType::Type getType();
  std::string getString();
  int getAmount();
  void addAmount(int n);
  void addAmountPerSecond(int a);
  void update();

private:
  RessourceType::Type type;
  int amount;
  int amountPerSecond;
};
