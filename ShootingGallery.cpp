#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <SFML/Graphics.hpp>
using std::cout;
using std::cin;

int main() {

  sf::RenderWindow window(sf::VideoMode(1280, 720), "Shooting Gallery");
  sf::CircleShape shape(120.f);
  sf::CircleShape small(10.f);

  shape.setFillColor(sf::Color::White);
  shape.setOutlineThickness(8.f);
  shape.setOutlineColor(sf::Color::Red);

  window.setFramerateLimit(10);

  while (window.isOpen()) {
    window.clear();
    //RANDOM GENERATOR//
    shape.setPosition(80,40);
    //USER INPUT//
    window.draw(shape);

    window.display();
  }
}
