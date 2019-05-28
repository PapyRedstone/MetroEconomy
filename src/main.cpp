#include "Tunnel.hpp"
#include <sol.hpp>

int main(){
  //Setting up window
  sf::RenderWindow window(sf::VideoMode(1200,800), "Metro"/* ,sf::Style::Fullscreen*/);
  window.setVerticalSyncEnabled(true);
  ImGui::SFML::Init(window);

  //Setting up level
  std::vector<Station> stations;
  std::vector<Tunnel> tunnels;

  sol::state luaState;
  luaState.open_libraries(sol::lib::base);
  luaState.script_file("ressources/script/setup.lua");

  sol::table stationsTable = luaState["stations"];
  if(!stationsTable.valid()){
    std::cerr << "Error loading sations in lua\n";
    return -1;
  }

  stationsTable.for_each([&](const sol::object& key, const sol::table& value){
      stations.push_back(std::string(value["name"]));
      stations.back().setPosition(value["position"][1], value["position"][2]);
    });

  sol::table tunnelsTable = luaState["tunnels"];
  if(!stationsTable.valid()){
    std::cerr << "Error loading tunnels in lua\n";
    return -1;
  }

  auto sizeOfStation = stations.size();
  tunnelsTable.for_each([&](const sol::object& key, const sol::table& value){
      if(value["from"].cast<int>() < sizeOfStation || value["to"].cast<int>() < sizeOfStation){
	std::cout << "a\n";
      }
      tunnels.push_back(Tunnel(stations[value["from"]], stations[value["to"]]));
    });

  //Needed for gui
  sf::Clock clock;

  while(window.isOpen()){
    //Managing event
    sf::Event event;
    while(window.pollEvent(event)){
      //Manage UI events
      ImGui::SFML::ProcessEvent(event);
      
      switch(event.type){
      case sf::Event::Closed:
	window.close();
	break;
	
      case sf::Event::MouseButtonPressed:
	if(event.mouseButton.button == sf::Mouse::Left){

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
	}

      default:
	break;
      }
    }

    //Drawing
    ImGui::SFML::Update(window, clock.restart());

    window.clear();
    for(auto &t:tunnels){
      window.draw(t);
    }
    for(auto &s:stations){
      window.draw(s);
      s.drawUI();
    }

    ImGui::SFML::Render(window);
    window.display();
  }

  return 0;
}
