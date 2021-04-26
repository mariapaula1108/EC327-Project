#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>
#include <iomanip>
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
    if (Mx > 535 && Mx < 715 && My > 230 && My < 300){
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      int level = 7;
      cout << "Easy" << endl;
      return level;
    }
  }
   // if ((Mx > shape.getPosition().x) && (Mx < (shape.getPosition().x - shape.getSize().x)) &&
   //   (My > shape.getPosition().y) && (My < (shape.getPosition().y - shape.getSize().x))) {
   //  if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
 if (Mx > 535 && Mx < 715 && My > 325 && My < 400){
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      int level = 8;
      cout << "Intermediate" << endl;
      return level;
    }
  } 
    
  if (Mx > 535 && Mx < 715 && My > 425 && My < 495){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      int level = 9;
      cout << "Hard" << endl;
      return level;
    }
  }

  if (Mx > 575 && Mx < 700 && My > 555 && My < 600){
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
      int level = 420;
      cout << "Exit" << endl;
      return level;
    }
  } 
    
  return 10;
}

int main() {

  int x = 2000;
  int y = 2000;
  int radius = 75;
  int score_num = 0;
  float timer = 3;
  int countdown = 31;
  float elapsed = 0;
  float target_count = 0;
  vector<float> storage; //Stores the time the player clicks on the target//

  sf::Clock clock; //Clock that dictates how long the target will last//
  sf::Clock master_time; //Clock that dictates how long the overall game will last//
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Aim Simulator");
  sf::CircleShape X_Large(radius);
  sf::CircleShape Large(radius*0.75);
  sf::CircleShape Medium(radius*0.5);
  sf::CircleShape Small(radius*0.25);
  sf::CircleShape X_Small(radius*0.125);
  sf::RectangleShape Easy(sf::Vector2f(180, 70));
  sf::RectangleShape Intermediate(sf::Vector2f(180, 70));
  sf::RectangleShape Hard(sf::Vector2f(180, 70));
  sf::RectangleShape Exit(sf::Vector2f(115, 45));
  sf::RectangleShape Restart(sf::Vector2f(240, 50));
  sf::Text words;
  sf::Text score;
  sf::Text hundred;
  sf::Text easy_word;
  sf::Text intermediate_word;
  sf::Text hard_word;
  //sf::Text menu_word;
  sf::Text restart_word;
  sf::Text time;
  sf::Text exit_word;
  sf::Text master_timer;
  sf::Texture menugrass;
  sf::Text PRE;
  sf::Text REACT;
  sf::Text PRE_word;
  sf::Text REACT_word;
  menugrass.loadFromFile("menu.png");
  sf::Sprite s(menugrass);
  sf::Texture mainbackg;
  mainbackg.loadFromFile("game.png");
  sf::Sprite q(mainbackg);
  sf::Texture ending;
  ending.loadFromFile("game.png");
  sf::Sprite k(ending);


  X_Large.setFillColor(sf::Color::White);
  Large.setFillColor(sf::Color::Black);
  Medium.setFillColor(sf::Color(0,0,255));
  Small.setFillColor(sf::Color::Red);
  X_Small.setFillColor(sf::Color::Yellow);
  Easy.setFillColor(sf::Color::Transparent);
  Intermediate.setFillColor(sf::Color::Transparent);
  Hard.setFillColor(sf::Color::Transparent);
  Exit.setFillColor(sf::Color::White);
  Restart.setFillColor(sf::Color::Transparent);


  sf::Font font;
  sf::Font font_num;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");
  font_num.loadFromFile("/usr/share/fonts/truetype/malayalam/Uroob-Regular.ttf");
  score.setFont(font_num);
  score.setCharacterSize(50);
  score.setString("Score: " + to_string(score_num));
  score.setFillColor(sf::Color::Black);
  hundred.setFont(font_num);
  hundred.setCharacterSize(40);
  hundred.setString("");
  easy_word.setFont(font);
  easy_word.setString("EASY");
  easy_word.setFillColor(sf::Color::Black);
  intermediate_word.setFont(font);
  intermediate_word.setCharacterSize(19);
  intermediate_word.setString("INTERMEDIATE");
  intermediate_word.setFillColor(sf::Color::Black);
  hard_word.setFont(font);
  hard_word.setString("HARD");
  hard_word.setFillColor(sf::Color::Black);
  //menu_word.setFont(font_num);
  //menu_word.setString("Main Menu");
  //menu_word.setCharacterSize(70);
  //menu_word.setFillColor(sf::Color(46, 67, 115));
  exit_word.setFont(font);
  exit_word.setString("EXIT");
  exit_word.setFillColor(sf::Color::Black);
  restart_word.setFont(font);
  restart_word.setString("RESTART");
  restart_word.setFillColor(sf::Color::Red);
  master_timer.setFont(font_num);
  master_timer.setCharacterSize(45);
  master_timer.setFillColor(sf::Color::Black);
  master_timer.setString("61");
  REACT.setFont(font_num);
  REACT.setCharacterSize(50);
  REACT.setFillColor(sf::Color::Black);
  PRE.setFont(font_num);
  PRE.setCharacterSize(50);
  PRE.setFillColor(sf::Color::Black);

 

  window.setFramerateLimit(40);

  while (window.isOpen()) {

    window.clear();
 
    //window.clear(sf::Color::White);
    window.draw(s);
                
    Easy.setPosition(535,230);
    Intermediate.setPosition(535,330);
    Hard.setPosition(535,425);
    Exit.setPosition(575,555);
    easy_word.setPosition(585, 245);
    intermediate_word.setPosition(560, 348);
    hard_word.setPosition(585, 440);
    //menu_word.setPosition(510, 75);
    exit_word.setPosition(595, 555);

   window.draw(Easy);
   window.draw(Intermediate);
   window.draw(Hard);
   //window.draw(Exit);
    window.draw(easy_word);
    window.draw(intermediate_word);
    window.draw(hard_word);
    //window.draw(menu_word);
    window.draw(exit_word);

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
      score.setPosition(0,0);
      master_timer.setPosition(600,10);
   
    //Level difficulty determined by variable timer
      if (menucase == 7)
        timer = 3;
      if (menucase == 8)
        timer = 1.5;
      if (menucase == 9)
        timer = 1;

      //Sets the condition to go to the next target after missing a target//

      if (clock.getElapsedTime().asSeconds() > timer) {
        x = rand() % ((1280-radius)+1);
        y = rand() % ((720-radius)+1);
        target_count++;
        clock.restart();
      }

      switch (bullet(X_Large, radius, window)) {
        case 1:
            score_num+=100;
            hundred.setPosition(200,0);
            hundred.setFillColor(sf::Color::Red);
            hundred.setString("+100");
            window.draw(hundred);
            score.setString("Score: " + to_string(score_num));
            x = rand() % ((1280-radius)+1);
            y = rand() % ((720-radius)+1);
            storage.push_back(clock.getElapsedTime().asSeconds());
            target_count++;
            clock.restart();
            break;
        case 2:
            score_num+=200;
            hundred.setPosition(200,0);
            hundred.setFillColor(sf::Color(255, 128, 0));
            hundred.setString("+200");
            window.draw(hundred);
            score.setString("Score: " + to_string(score_num));
            x = rand() % ((1280-radius)+1);
            y = rand() % ((720-radius)+1);
            storage.push_back(clock.getElapsedTime().asSeconds());
            target_count++;
            clock.restart();
            break;
        case 3:
            score_num+=300;
            hundred.setPosition(200,0);
            hundred.setFillColor(sf::Color::Yellow);
            hundred.setString("+300");
            window.draw(hundred);
            score.setString("Score: " + to_string(score_num));
            x = rand() % ((1280-radius)+1);
            y = rand() % ((720-radius)+1);
            storage.push_back(clock.getElapsedTime().asSeconds());
            target_count++;
            clock.restart();
            break;
        case 4:
            score_num+=500;
            hundred.setPosition(200,0);
            hundred.setFillColor(sf::Color(0, 102, 0));
            hundred.setString("+500");
            window.draw(hundred);
            score.setString("Score: " + to_string(score_num));
            x = rand() % ((1280-radius)+1);
            y = rand() % ((720-radius)+1);
            storage.push_back(clock.getElapsedTime().asSeconds());
            target_count++;
            clock.restart();
            break;
        case 5:
            score_num+=1000;
            hundred.setPosition(200,0);
            hundred.setFillColor(sf::Color::Green);
            hundred.setString("+1000");
            window.draw(hundred);
            score.setString("Score: " + to_string(score_num));
            x = rand() % ((1280-radius)+1);
            y = rand() % ((720-radius)+1);
            target_count++;
            storage.push_back(clock.getElapsedTime().asSeconds());
            clock.restart();
            break;
        default:
            break;
      }

     
      if (floor(master_time.getElapsedTime().asSeconds()) > elapsed) {
        countdown = countdown - 1;
        elapsed = master_time.getElapsedTime().asSeconds();
        master_timer.setString(to_string(countdown));
      }

      window.draw(X_Large);
      window.draw(Large);
      window.draw(Medium);
      window.draw(Small);
      window.draw(X_Small);
      window.draw(score);
      window.draw(master_timer);

      window.display();
      
      //Once the game ends, the window closes//

      if (countdown == 0) {
        while (window.isOpen()) {
        window.clear();
        countdown = 31;
        float dummy = score_num;
        float precision = (dummy / (target_count * 1000)) * 100;
        std::ostringstream stream;
        stream << std::fixed;
        stream << std::setprecision(2);
        stream << precision;
        float sum = 0;
        for (int j = 0; j < storage.size(); j++) {
          sum += storage.at(j);
        }
        float react = (sum/storage.size()) * 100;
        std::ostringstream stream2;
        stream2 << std::fixed;
        stream2 << std::setprecision(3);
        stream2 << react;

        //Exit.setPosition(500,500);
        exit_word.setPosition(580, 505);
        Restart.setPosition(500,600);
        restart_word.setPosition(550,605);
        score.setPosition(480,100);
        PRE.setString("Precision: " + stream.str() + "%");
        PRE.setPosition(480, 150);
        REACT.setString("Reaction: " + stream2.str()+"ms");
        REACT.setPosition(480,200);

        //window.draw(Exit);
        window.draw(k);
        window.draw(exit_word);
        window.draw(Restart);
        window.draw(restart_word);
        window.draw(score);
        window.draw(PRE);
        window.draw(REACT);

        window.display();

        float Mx_end = sf::Mouse::getPosition(window).x;
        float My_end = sf::Mouse::getPosition(window).y;

        if (Mx_end > 500 && Mx_end < 740 && My_end > 600 && My_end < 650){
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
            score_num = 0;
            target_count = 0;
            storage.clear();
            score.setString("Score: " + to_string(score_num));
            break;
          }
        }

        if (Mx_end > 500 && Mx_end < 740 && My_end > 500 && My_end < 550){
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == 1) {
            window.close();
          }
        }
      }
      break;
      }
    }
  }
  if (menucase == 420) {
  window.close();
  }
}
}
