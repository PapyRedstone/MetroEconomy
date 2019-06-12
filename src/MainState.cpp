#include "MainState.hpp"

#include <iostream>
#include <sol/sol.hpp>
#include "imgui.hpp"
#include "imgui-SFML.hpp"

/*
============================================
BaseState
============================================
*/
BaseState::BaseState(sf::RenderWindow& win): window{win}
{}

std::shared_ptr<BaseState> BaseState::changeState(){
  exit();
  return newState;
}

/*
============================================
MenuState
============================================
*/
MenuState::MenuState(sf::RenderWindow &win):BaseState{win}
{}

void MenuState::processEvent(const sf::Event& event){
  
}

bool MenuState::draw(){
  ImGui::SFML::Update(window, clock.restart());
  window.clear();

  bool changeStateNeeded = false;
  
  if(ImGui::Begin("Menu")){
    if(ImGui::Button("Go to Game")){
      newState = std::make_shared<GameState>(window);
      changeStateNeeded = true;
    }
  }
  
  ImGui::End();

  ImGui::SFML::Render(window);
  window.display();

  return changeStateNeeded;
}

void MenuState::exit(){
  
}

/*
============================================
GameState::Constructor
============================================
*/
GameState::GameState(sf::RenderWindow& win):BaseState{win}, showMenu{false}
{
  //Opening lua state
  sol::state luaState;
  luaState.open_libraries(sol::lib::base);
  luaState.script_file("ressources/script/setup.lua");

  //Checking stations table is present in lua
  sol::table stationsTable = luaState["stations"];
  if(!stationsTable.valid()){
    std::cerr << "Error loading sations in lua\n";
    return;
  }

  //Checking tunnels table is present in lua
  sol::table tunnelsTable = luaState["tunnels"];
  if(!stationsTable.valid()){
    std::cerr << "Error loading tunnels in lua\n";
    return ;
  }

  //Creating stations
  stationsTable.for_each([&](const sol::object& key, const sol::table& value){
      stations.push_back(std::string(value["name"]));
      stations.back().setPosition(value["position"][1], value["position"][2]);
      stations.back().setID(value["idPlayer"]);
    });

  //Creating tunnels
  auto sizeOfStation = stations.size();
  tunnelsTable.for_each([&](const sol::object& key, const sol::table& value){
      unsigned from = value["from"];
      unsigned to = value["to"];
      if( from >= sizeOfStation ||
	  to >= sizeOfStation || 
	  from < 0 ||
	  to < 0 ){//Checking range of stations id
	std::cerr << "ERROR: when creating tunnels, one index isn't valid" << sizeOfStation << " : " << static_cast<unsigned>(value["from"]) << "," << static_cast<unsigned>(value["to"]) << "\n";
	return;
      }
      tunnels.push_back(Tunnel(stations[value["from"]], stations[value["to"]]));
    });
}

/*
============================================
GameState::ProcessEvent
============================================
*/
void GameState::processEvent(const sf::Event& event){
  switch(event.type){
  case sf::Event::MouseButtonPressed:
    switch(event.mouseButton.button){

    case sf::Mouse::Left:  
      //Switch UI show if click on a station
      for(auto& s: stations){
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f circlePos = s.getPosition();
	circlePos += sf::Vector2f(s.getRadius(), s.getRadius());
	
	//(x - center_x)^2 + (y - center_y)^2 < radius^2
	if(std::pow(mousePos.x - circlePos.x, 2) +
	   std::pow(mousePos.y - circlePos.y, 2) < std::pow(s.getRadius(),2)){
	  s.switchUIShow();
	}
      }
      break; //End of Mouse::left

    default: break;
    }
    break;//End of Event::MouseButtonPressed

  case sf::Event::KeyPressed:
    switch(event.key.code){
    case sf::Keyboard::Escape:
      showMenu = !showMenu;
      break;

    default: break;
    }
    break; // End Event::KeyPressed
    
  default: break;
  }
}

/*
============================================
GameState::draw
============================================
*/
bool GameState::draw(){
  ImGui::SFML::Update(window, clock.restart());
  window.clear();

  bool changeStateNeeded = false;

  if(showMenu){
    if(ImGui::Begin("Game")){
      if(ImGui::Button("Go to Menu")){
	newState = std::make_shared<MenuState>(window);
	changeStateNeeded = true;
      }
    }
    
    ImGui::End();
  }
  
  for(auto &t:tunnels){
    window.draw(t);
  }
  for(auto &s:stations){
    window.draw(s);
    s.drawUI();
  }

  ImGui::SFML::Render(window);
  window.display();

  return changeStateNeeded;
}

/*
============================================
GameState::exit
============================================
*/
void GameState::exit(){
  //TODO add saving
}
