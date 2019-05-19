#include "Station.hpp"

Station::Station():sf::CircleShape{30}
{
  setOutlineColor(sf::Color::Blue);
  setOutlineThickness(5);
  setFillColor(sf::Color::Red);
}

void Station::addTunnel(Tunnel& t){
  connectedTunnels.push_back(t);
}

Tunnel::Tunnel(Station& s1, Station& s2):station1{s1},station2{s2}
{
  station1.addTunnel(*this);
  station2.addTunnel(*this);

  
  sf::Vector2f p1 = station1.getPosition(), p2=station2.getPosition();
  float distance = std::sqrt(std::pow(p1.x-p2.x, 2) + std::pow(p1.y-p2.y, 2));

  setSize(sf::Vector2f(distance, 40));

  sf::Vector2f p;
  if(p1.x < p2.x){
    p = p1;
  }else{
    p = p2;
  }
  setPosition(p + sf::Vector2f(3/2*station1.getRadius(), station1.getRadius()/2));
  setFillColor(sf::Color::Green);

  float angle = std::atan((p1.y-p2.y) / (p1.x-p2.x));
  setRotation(angle*180/std::acos(-1)); //convert radians to degree (acos(-1) == PI)
}
