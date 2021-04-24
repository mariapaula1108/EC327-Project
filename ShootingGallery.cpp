#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>
using std::cout;
using std::cin;
using std::to_string;
using std::vector;

//Fuction will tell if the mouse was clicked inside the target//
int bullet(sf::CircleShape &shape, int radius, sf::RenderWindow &field) {
  float Mx, My;
  Mx = sf::Mouse::getPosition(field).x;
  My = sf::Mouse::getPosition(field).y;
  float distance = sqrt(pow(Mx-(shape.getPosition().x+radius),2)+pow(My-(shape.getPosition().y+radius),2));
  if (distance < radius && distance > 0.75*radius) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      return 1;
    }
  } else if (distance < 0.75*radius && distance > 0.5*radius) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      return 2;
    }
  } else if (distance < 0.5*radius && distance > 0.25*radius) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      return 3;
    }
  } else if (distance < 0.25*radius && distance > 0.125*radius) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      return 4;
    }
  } else if (distance < 0.125*radius && distance >= 0) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      return 5;
    }
  }
  return 6;
}

bool menu(sf::RectangleShape &shape, sf::RenderWindow &field) {
  float Mx, My;
  Mx = sf::Mouse::getPosition(field).x;
  My = sf::Mouse::getPosition(field).y;
  if ((Mx > shape.getPosition().x) && (Mx < (shape.getPosition().x - shape.getSize().x)) &&
    (My > shape.getPosition().y) && (My < (shape.getPosition().y - shape.getSize().x))) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      return true;
    }
  }
  return false;
}

int main() {

  int x = 640;
  int y = 360;
  int radius = 75;
  int score_num = 0;
  float timer = 5;
  float game_time = 20;
  vector<float> storage; //Stores the time the player clicks on the target//

  sf::Clock clock; //Clock that dictates how long the target will last//
  sf::Clock master_time; //Clock that dictates how long the overall game will last//
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Shooting Gallery");
  sf::CircleShape X_Large(radius);
  sf::CircleShape Large(radius*0.75);
  sf::CircleShape Medium(radius*0.5);
  sf::CircleShape Small(radius*0.25);
  sf::CircleShape X_Small(radius*0.125);
  sf::RectangleShape Easy(sf::Vector2f(120, 50));
  sf::Text words;
  sf::Text score;
  sf::Text hundred;
  sf::Text easy_word;
  sf::Text time;

  X_Large.setFillColor(sf::Color::White);
  Large.setFillColor(sf::Color::Black);
  Medium.setFillColor(sf::Color::Blue);
  Small.setFillColor(sf::Color::Red);
  X_Small.setFillColor(sf::Color::Yellow);
  Easy.setFillColor(sf::Color::Green);

  sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");
  words.setFont(font);
  words.setString("Score:");
  words.setFillColor(sf::Color::White);
  score.setFont(font);
  score.setString("");
  score.setFillColor(sf::Color::White);
  hundred.setFont(font);
  hundred.setString("");
  easy_word.setFont(font);
  easy_word.setString("EASY");
  easy_word.setFillColor(sf::Color::Green);

  window.setFramerateLimit(10);

  while (window.isOpen()) {
    window.clear();

    X_Large.setPosition(x,y);
    Large.setPosition(x+(radius*0.25),y+(radius*0.25));
    Medium.setPosition(x+(radius*0.5),y+(radius*0.5));
    Small.setPosition(x+(radius*0.75),y+(radius*0.75));
    X_Small.setPosition(x+(radius*0.875),y+(radius*0.875));
    words.setPosition(0,0);
    score.setPosition(0,30);

    //Sets the condition to go to the next target after missing a target//

    if (clock.getElapsedTime().asSeconds() > timer) {
      x = rand() % ((1280-radius)+1);
      y = rand() % ((720-radius)+1);
      clock.restart();
    }

    switch (bullet(X_Large, radius, window)) {
      case 1:
          score_num+=100;
          hundred.setPosition(65,30);
          hundred.setFillColor(sf::Color::Red);
          hundred.setString("+100");
          window.draw(hundred);
          score.setString(to_string(score_num));
          x = rand() % ((1280-radius)+1);
          y = rand() % ((720-radius)+1);
          storage.push_back(clock.getElapsedTime().asSeconds());
          clock.restart();
          break;
      case 2:
          score_num+=200;
          hundred.setPosition(65,30);
          hundred.setFillColor(sf::Color(255, 128, 0));
          hundred.setString("+200");
          window.draw(hundred);
          score.setString(to_string(score_num));
          x = rand() % ((1280-radius)+1);
          y = rand() % ((720-radius)+1);
          storage.push_back(clock.getElapsedTime().asSeconds());
          clock.restart();
          break;
      case 3:
          score_num+=300;
          hundred.setPosition(65,30);
          hundred.setFillColor(sf::Color::Yellow);
          hundred.setString("+300");
          window.draw(hundred);
          score.setString(to_string(score_num));
          x = rand() % ((1280-radius)+1);
          y = rand() % ((720-radius)+1);
          storage.push_back(clock.getElapsedTime().asSeconds());
          clock.restart();
          break;
      case 4:
          score_num+=500;
          hundred.setPosition(65,30);
          hundred.setFillColor(sf::Color(0, 102, 0));
          hundred.setString("+500");
          window.draw(hundred);
          score.setString(to_string(score_num));
          x = rand() % ((1280-radius)+1);
          y = rand() % ((720-radius)+1);
          storage.push_back(clock.getElapsedTime().asSeconds());
          clock.restart();
          break;
      case 5:
          score_num+=1000;
          hundred.setPosition(65,30);
          hundred.setFillColor(sf::Color::Green);
          hundred.setString("+1000");
          window.draw(hundred);
          score.setString(to_string(score_num));
          x = rand() % ((1280-radius)+1);
          y = rand() % ((720-radius)+1);
          clock.restart();
          storage.push_back(clock.getElapsedTime().asSeconds());
          break;
      default:
          break;
    }

    window.draw(X_Large);
    window.draw(Large);
    window.draw(Medium);
    window.draw(Small);
    window.draw(X_Small);
    window.draw(score);
    window.draw(words);

    window.display();
    
    //Once the game ends, the window closes//

    if (master_time.getElapsedTime().asSeconds() > game_time) {
      window.close();
    }
  }

  //Calculates the average reaction speed of the player and prints it in the terminal//

  float sum = 0;

  for (int j = 0; j < storage.size(); j++) {
    sum += storage.at(j);
  }

  cout << "Reaction time: " << sum/storage.size() << "\n";
}
