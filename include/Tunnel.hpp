#pragma once

#include <SFML/Graphics.hpp>

#include "Station.hpp"

class Tunnel: public sf::RectangleShape{
public:
  Tunnel(Station& s1, Station& s2);
  

private:
  Station &station1, &station2;
};
