#pragma once

#include "Ressource.hpp"

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Tunnel;

class Station: public sf::CircleShape{
public:
  Station(std::string n);

  void setID(ID newId);
  void addTunnel(Tunnel& t);
  void drawUI();
  void switchUIShow();
  
private:
  std::vector<Ressource> ressources;
  std::vector<Tunnel> connectedTunnels;
  bool isUIShow;
  std::string name;
  ID idOwner;
};
