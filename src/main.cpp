#include <SFML/Graphics.hpp>
#include <iostream>
#include "Station.hpp"
#include <vector>

int main(){
  sf::RenderWindow window(sf::VideoMode(800,600), "Metro");
  window.setFramerateLimit(60);

  std::vector<Station> stations(4);
  std::vector<Tunnel> tunnels;

  stations[0].setPosition(50,50);
  stations[1].setPosition(400,50);
  stations[2].setPosition(50,400);
  stations[3].setPosition(400,400);

  tunnels.push_back(Tunnel(stations[0], stations[1]));
  tunnels.push_back(Tunnel(stations[2], stations[0]));
  tunnels.push_back(Tunnel(stations[1], stations[2]));
  tunnels.push_back(Tunnel(stations[1], stations[3]));

  while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
      switch(event.type){
      case sf::Event::Closed:
	window.close();
	break;

      default:
	break;
      }
    }

    window.clear();
    for(auto &t:tunnels){
      window.draw(t);
    }
    for(auto &s:stations){
      window.draw(s);
    }
    window.display();
  }

  return 0;
}
