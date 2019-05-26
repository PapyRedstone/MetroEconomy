#include "Ressource.hpp"

Ressource::Ressource(RessourceType::Type t):type{t}, amount{0}
{}

int Ressource::getAmount(){
  return amount;
}

RessourceType::Type Ressource::getType(){
  return type;
}

std::string Ressource::getString(){
  /*  switch(type){
  case RessourceType::Wood:
    return "Wood";

  case RessourceType::Food:
    return "Food";

  default:
    return "NoRe";
    }*/
  return RessourceType::StringType[type];
}

void Ressource::addAmount(int n){
  amount += n;
}

void Ressource::addAmountPerSecond(int a){
  amountPerSecond += a;
}

void Ressource::update(){
  amount += amountPerSecond;
}
