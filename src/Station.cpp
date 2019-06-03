#include "Station.hpp"
#include "Tunnel.hpp"

#include "imgui.hpp"
#include "imgui-SFML.hpp"

Station::Station(std::string n):sf::CircleShape{10}, isUIShow{false}, name{n}
{
  //Beatiful colors
  setOutlineColor(sf::Color::Blue);
  setOutlineThickness(2);
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
  if(!isUIShow){
    return;
  }

  //Showing UI for a station
  if(!ImGui::Begin(name.data(), nullptr, ImGuiWindowFlags_AlwaysAutoResize)){
    ImGui::End();
    return;
  }

  for(auto& res: ressources){
    ImGui::LabelText(std::to_string(res.getAmount()).data(), res.getString().data());
    //ImGui::LabelText(std::to_string(res.getAmount()).data(), "OK"); //No string format error
  }
  
  ImGui::End();
}

void Station::switchUIShow(){
  isUIShow = !isUIShow;
}
