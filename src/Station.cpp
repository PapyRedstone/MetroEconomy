#include "Station.hpp"
#include "Tunnel.hpp"

#include "imgui.hpp"
#include "imgui-SFML.hpp"

/*
============================================
Constructor
============================================
*/
Station::Station(std::string n):sf::CircleShape{10}, isUIShow{false}, name{n}, idOwner{-1}
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

/*
============================================
addTunnel
============================================
*/
void Station::addTunnel(Tunnel& t){
  connectedTunnels.push_back(t);
}

/*
============================================
drawUI
============================================
*/
void Station::drawUI(){
  if(!isUIShow){
    return;
  }

  //Showing UI for a station
  if(ImGui::Begin(name.data(), nullptr, ImGuiWindowFlags_AlwaysAutoResize)){
    if(idOwner == 0){ //ID 0 is the player
      for(auto& res: ressources){
	ImGui::LabelText(std::to_string(res.getAmount()).data(), res.getString().data());
	//ImGui::LabelText(std::to_string(res.getAmount()).data(), "OK"); //No string format error
      }
    }
    else{
      ImGui::Text("This station isn't yours");
    }
  }
  
  ImGui::End();
}

/*
============================================
SwitchUiShow
============================================
*/
void Station::switchUIShow(){
  isUIShow = !isUIShow;
}

/*
============================================
setID
============================================
*/
void Station::setID(ID newId){
  idOwner = newId;
}

