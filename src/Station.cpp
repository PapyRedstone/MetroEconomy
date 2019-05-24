#include "Station.hpp"

Station::Station(std::string n):sf::CircleShape{30}, isUIShow{true}, name{n}
{
  setOutlineColor(sf::Color::Blue);
  setOutlineThickness(5);
  setFillColor(sf::Color::Red);

  for(RessourceType::Type t: RessourceType::All){
    ressources.push_back(t);
  }
}

void Station::addTunnel(Tunnel& t){
  connectedTunnels.push_back(t);
}

void Station::drawUI(){
  if(!isUIShow){
    return;
  }

  ImGui::Begin(name.data());

  if(ImGui::Button("Button")){
    std::cout << name << "\n";
  }
  
  ImGui::End();
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
  float pi = std::acos(-1);
  while(angle >= pi){
    angle -= 2*pi;
  }
  while(angle < pi){
    angle += 2*pi;
  }
  setRotation(angle*180/pi); //convert radians to degree (acos(-1) == PI)
}
