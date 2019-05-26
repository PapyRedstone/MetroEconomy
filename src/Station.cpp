#include "Station.hpp"
#include "Tunnel.hpp"

Station::Station(std::string n):sf::CircleShape{30}, isUIShow{false}, name{n}
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
    
  if(!ImGui::Begin(name.data(), nullptr, ImGuiWindowFlags_AlwaysAutoResize)){
    ImGui::End();
    return;
  }

  for(auto& res: ressources){
    ImGui::LabelText(std::to_string(res.getAmount()).data(), res.getString().data());
  }
  
  ImGui::End();
}

void Station::switchUIShow(){
  isUIShow = !isUIShow;
}
