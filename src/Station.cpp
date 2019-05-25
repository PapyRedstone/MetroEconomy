#include "Station.hpp"
#include "Tunnel.hpp"

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

void Station::switchUIShow(){
  isUIShow = !isUIShow;
}
