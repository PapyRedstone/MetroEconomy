#include "Station.hpp"
#include "Tunnel.hpp"

#include "imgui.hpp"
#include "imgui-SFML.hpp"

/*
============================================
Constructor
============================================
*/
Station::Station(std::string n):isUIShow{false}, name{n}, idOwner{-1}, shape{10}
{
  //Beatiful colors
  shape.setOutlineColor(sf::Color::Blue);
  shape.setOutlineThickness(2);
  shape.setFillColor(sf::Color::Red);

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

/*
============================================
getPosition
============================================
*/
sf::Vector2f Station::getPosition(){
  return shape.getPosition();
}

/*
============================================
setPosition
============================================
*/
void Station::setPosition(float x, float y){
  shape.setPosition(x, y);
}

/*
============================================
getRadius
============================================
*/
float Station::getRadius(){
  return shape.getRadius();
}

/*
============================================
draw
============================================
*/
void Station::draw(sf::RenderWindow& win){
  win.draw(shape);
}
