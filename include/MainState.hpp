#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Tunnel.hpp"

class BaseState{
public:
  BaseState(sf::RenderWindow& win);
  virtual void processEvent(const sf::Event&) =0;
  virtual bool draw() =0;
  virtual void exit() =0;

  virtual std::shared_ptr<BaseState> changeState();
  
protected:
  sf::RenderWindow &window;
  sf::Clock clock;
  std::shared_ptr<BaseState> newState;
};

class MenuState: public BaseState{
public:
  MenuState(sf::RenderWindow &win);
  virtual void processEvent(const sf::Event& event);
  virtual bool draw();
  virtual void exit();
};

class GameState: public BaseState{
public:
  GameState(sf::RenderWindow& win);
  virtual void processEvent(const sf::Event& event);
  virtual bool draw();
  virtual void exit();

private:
  std::vector<Station> stations;
  std::vector<Tunnel> tunnels;
  bool showMenu;
};
