#pragma once

#include <SFML/Graphics.hpp>

#include "Station.hpp"

class Tunnel{
public:
  Tunnel(Station& s1, Station& s2);

  void draw(sf::RenderWindow& win);

private:
  Station &station1, &station2;
  sf::RectangleShape shape;
};
