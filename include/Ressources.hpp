#pragma once

enum class RessourceType{
  Wood,
  Food
};

class Ressource{
public:
  Ressource(RessourceType t);

  RessourceType getType();
  int getAmount();
  void addAmount(int n);

private:
  RessourceType type;
  int amount;
};
