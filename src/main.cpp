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

  stations[0].setPosition(50,50);
  stations[1].setPosition(400,50);
  stations[2].setPosition(50,400);
  stations[3].setPosition(400,400);

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
