#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>

#include "Tunnel.hpp"

int main(){
  sf::RenderWindow window(sf::VideoMode(800,600), "Metro");
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  ImGui::SFML::Init(window);

  std::vector<Station> stations;
  std::vector<Tunnel> tunnels;

  for(unsigned i{0}; i<4; i++){
    stations.push_back(std::string(1,'A'+i));
  }

  stations[0].setPosition( 50,  50);
  stations[1].setPosition(400,  50);
  stations[2].setPosition( 50, 400);
  stations[3].setPosition(400, 400);

  tunnels.push_back(Tunnel(stations[0], stations[1]));
  tunnels.push_back(Tunnel(stations[2], stations[0]));
  tunnels.push_back(Tunnel(stations[1], stations[2]));
  tunnels.push_back(Tunnel(stations[1], stations[3]));

  sf::Clock clock;

  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      ImGui::SFML::ProcessEvent(event);
      
      switch(event.type){
      case sf::Event::Closed:
	window.close();
	break;

      case sf::Event::MouseButtonPressed:
	if(event.mouseButton.button == sf::Mouse::Left){
	  for(auto& s: stations){
	    //(x - center_x)^2 + (y - center_y)^2 < radius^2
	    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	    sf::Vector2f circlePos = s.getPosition();
	    circlePos += sf::Vector2f(s.getRadius(), s.getRadius());
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
