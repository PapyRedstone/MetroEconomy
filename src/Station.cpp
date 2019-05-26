#include "Station.hpp"
#include "Tunnel.hpp"

Station::Station(std::string n):sf::CircleShape{30}, isUIShow{false}, name{n}
{
  //Beatiful colors
  setOutlineColor(sf::Color::Blue);
  setOutlineThickness(5);
  setFillColor(sf::Color::Red);

  //Setting up ressources
  for(RessourceType::Type t: RessourceType::All){
    ressources.push_back(t);
  }
}

void Station::addTunnel(Tunnel& t){
  connectedTunnels.push_back(t);
}

void Station::drawUI(){
  //Showing UI for a station
  if(isUIShow){
    ImGui::Begin(name.data());
    
    if(ImGui::Button("Button")){
      std::cout << name << "\n";
    }
    
    ImGui::End();
  }
}

void Station::switchUIShow(){
  isUIShow = !isUIShow;
}
