#include <SFML/Graphics.hpp>
#include <iostream>

int main(){
  sf::RenderWindow window(sf::VideoMode(800,600), "Metro");

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
    
    window.display();
  }

  return 0;
}
