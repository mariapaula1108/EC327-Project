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
using std::endl;

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

int menu(sf::RenderWindow &field) {
  
  float Mx, My;
  Mx = sf::Mouse::getPosition(field).x;
  My = sf::Mouse::getPosition(field).y;
    if (Mx > 500 && Mx < 740 && My > 200 && My < 250){
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      int level = 7;
      cout << "easy" << endl;
      return level;
    }
  }
   // if ((Mx > shape.getPosition().x) && (Mx < (shape.getPosition().x - shape.getSize().x)) &&
   //   (My > shape.getPosition().y) && (My < (shape.getPosition().y - shape.getSize().x))) {
   //  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
 if (Mx > 500 && Mx < 740 && My > 300 && My < 350){
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      int level = 8;
      cout << "Intermediate" << endl;
      return level;
    }
  } 
    
   if (Mx > 500 && Mx < 740 && My > 400 && My < 450){
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      int level = 9;
      cout << "hard" << endl;
      return level;
    }
  } 
    
  return 10;
}

int main() {

  int x = 640;
  int y = 360;
  int radius = 75;
  int score_num = 0;
  float timer = 5;
  float game_time = 35;
  vector<float> storage; //Stores the time the player clicks on the target//

  sf::Clock clock; //Clock that dictates how long the target will last//
  sf::Clock master_time; //Clock that dictates how long the overall game will last//
  sf::RenderWindow window(sf::VideoMode(800, 600), "Shooting Gallery");
  sf::CircleShape X_Large(radius);
  sf::CircleShape Large(radius*0.75);
  sf::CircleShape Medium(radius*0.5);
  sf::CircleShape Small(radius*0.25);
  sf::CircleShape X_Small(radius*0.125);
  sf::RectangleShape Easy(sf::Vector2f(240, 50));
  sf::RectangleShape Intermediate(sf::Vector2f(240, 50));
  sf::RectangleShape Hard(sf::Vector2f(240, 50));
  sf::Text words;
  sf::Text score;
  sf::Text hundred;
  sf::Text easy_word;
  sf::Text intermediate_word;
  sf::Text hard_word;
  sf::Text menu_word;
  sf::Text time;
  sf::Texture menugrass;
  menugrass.loadFromFile("grass3.png");
  sf::Sprite s(menugrass);
  sf::Texture mainbackg;
  mainbackg.loadFromFile("grass3.png");
  sf::Sprite q(mainbackg);


  X_Large.setFillColor(sf::Color::White);
  Large.setFillColor(sf::Color::Black);
  Medium.setFillColor(sf::Color::Blue);
  Small.setFillColor(sf::Color::Red);
  X_Small.setFillColor(sf::Color::Yellow);
  Easy.setFillColor(sf::Color::White);
  Medium.setFillColor(sf::Color::White);
  Hard.setFillColor(sf::Color::White);


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
  intermediate_word.setFont(font);
  intermediate_word.setString("INTERMEDIATE");
  intermediate_word.setFillColor(sf::Color::Magenta);
  hard_word.setFont(font);
  hard_word.setString("HARD");
  hard_word.setFillColor(sf::Color::Red);
  menu_word.setFont(font);
  menu_word.setString("Menu");
  menu_word.setFillColor(sf::Color::Cyan);

  window.setFramerateLimit(7);

  while (window.isOpen()) {
    window.clear();
 
    //window.clear(sf::Color::White);
    window.draw(s);
                
    Easy.setPosition(500,400);
    Intermediate.setPosition(500,300);
    Hard.setPosition(500,200);
    easy_word.setPosition(580, 205);
    intermediate_word.setPosition(510, 305);
    hard_word.setPosition(580, 405);
    menu_word.setPosition(580, 100);

    window.draw(Easy);
    window.draw(Intermediate);
    window.draw(Hard);
    window.draw(easy_word);
    window.draw(intermediate_word);
    window.draw(hard_word);
    window.draw(menu_word);

    window.display();
    

int menucase = menu(window);

if (menucase == 7 || menucase == 8 || menucase == 9) {

while(window.isOpen()){
  window.clear();
 
    window.draw(q);
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

 //Level difficulty determined by variable timer
 if (menucase == 8)
   timer = 2.5;
 if (menucase == 9)
   timer = 1.5;

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
}
}
  //Calculates the average reaction speed of the player and prints it in the terminal//

  float sum = 0;

  for (int j = 0; j < storage.size(); j++) {
    sum += storage.at(j);
  }

  cout << "Reaction time: " << sum/storage.size() << "\n";

}