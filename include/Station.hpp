#pragma once

#include "Ressource.hpp"

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Tunnel;

class Station{
public:
  Station(std::string n);

  void setID(ID newId);
  void addTunnel(Tunnel& t);
  void drawUI();
  void switchUIShow();
  
  sf::Vector2f getPosition();
  void setPosition(float x, float y);
  float getRadius();
  void draw(sf::RenderWindow& win);
  
private:
  std::vector<Ressource> ressources;
  std::vector<Tunnel> connectedTunnels;
  bool isUIShow;
  std::string name;
  ID idOwner;
  sf::CircleShape shape;
};
