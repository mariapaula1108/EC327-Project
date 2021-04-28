Aim Simulator

This program uses SFML to provide the graphics of the game.
To run the program you will need to compile the c++ file in the terminal.
Start by cloning the files in the terminal with this: git clone https://github.com/mariapaula1108/EC327-Project.git
Then to run the program make sure you are in the correct files:
cd EC327-Project 
cd ShootingGallery 
Compile using this: g++ ShootingGalleryWithMenu.cpp -o AS -lsfml-graphics -lsfml-window -lsfml-system
Finally, to run the program just type: AS
The program will open and the user can begin playing the game. 

Instructions:

The goal of the game is to get the highest score possible and the highest precision percentage, while also getting a low average reaction time.
Game starts at the main menu where the user can select the level of
difficulty or the exit button which closes the game.
Once the level of difficulty is chosen, the player has to click with their mouse
the targets that appear randomly in the screen.
In order to get a high score, the player wants to get as close to the bullseye as possible everytime.
The outer ring is worth 100 points, the next ring is worth 200, the following is 300, then 400, and the bullseye is 1000.
The player is given 60 seconds to hit the targets and after completed they will be shown the results:
Precision
Score
Raction Time

The player can then decide if they want to restart back to the menu to play again or just exit the game
completely.
