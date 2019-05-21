#include "Ressource.hpp"

Ressource::Ressource(RessourceType::Type t):type{t}
{}

int Ressource::getAmount(){
  return amount;
}

RessourceType::Type Ressource::getType(){
  return type;
}

void Ressource::addAmount(int n){
  amount += n;
}
