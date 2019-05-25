#pragma once

#include "imgui.hpp"
#include "imgui-SFML.hpp"

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>

#include "Ressource.hpp"

class Tunnel;

class Station: public sf::CircleShape{
public:
  Station(std::string n);

  void addTunnel(Tunnel& t);
  void drawUI();
  void switchUIShow();
  
private:
  std::vector<Ressource> ressources;
  std::vector<Tunnel> connectedTunnels;
  bool isUIShow;
  std::string name;
};
