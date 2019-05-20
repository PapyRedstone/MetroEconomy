#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <map>

#include "Ressource.hpp"

class Tunnel;

class Station: public sf::CircleShape{
public:
  Station();

  void addTunnel(Tunnel& t);
  
private:
  //std::vector<>
  std::vector<Tunnel> connectedTunnels;
};

class Tunnel: public sf::RectangleShape{
public:
  Tunnel(Station& s1, Station& s2);
  

private:
  Station &station1, &station2;
};
