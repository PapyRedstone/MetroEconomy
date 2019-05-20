#include "Ressource.hpp"

Ressource::Ressource(RessourceType t):type{t}
{}

int Ressource::getAmount(){
  return amount;
}

RessourceType Ressource::getType(){
  return type;
}

void Ressource::addAmount(int n){
  amount += n;
}
