#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/GameEngine/Input/InputManager.h"
#include "../include/GameEngine/objects/ObjectManager.h"
#include "../include/GameEngine/UI/UiManager.h"

using namespace std;

//#varibles#//
//window varibles//
int ScreenWidth = 800;
int ScreenHeight = 650;
//Scene handing varibles//
bool bPlaying = false;
bool bInMenu = true;
bool bPlayed = false;
bool bWin = false;
//game varibles//
int difficulty = 1;

//CLASSES//
InputManager inputManager;
Object objects;
Menu menu;

/// <summary>
/// Handles loading the game
/// - Creates window
/// - Loads up menu ui
/// - Handle in menu input like start, and difficulty
/// - Loads up game
/// - foward game input to input manager
/// - display win/loss
/// - loops
/// </summary>
/// <returns></returns>
int main() {
	//load in images and sou
	//objects.loadImageAll();
	//render window
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Snake");
	window.setFramerateLimit(30);
	menu.loadAllImages();
	//window open
	while (window.isOpen()) {
		//event loop
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			//INPUT HANDLING//
			if (event.type == sf::Event::KeyPressed) {
				//in start screen
				if (bInMenu == true && bPlayed == false) {
					if (event.key.code == sf::Keyboard::Space) {
						bPlaying = true;
						bInMenu = false;
						objects.loadImageAll();
					}
					if (event.key.code == sf::Keyboard::Right)
					{
						difficulty = difficulty + 1;
					}
					if (event.key.code == sf::Keyboard::Left)
					{
						if (difficulty != 1)
						{
							difficulty = difficulty - 1;
						}
					}
					//printf("%i \n",difficulty);
					menu.setText(0, difficulty);

				}
				else if (bInMenu == true && bPlayed == true)
				{

					if (event.key.code == sf::Keyboard::Space) {
						bPlayed = false;
					}

				}

				//if game is playing
				if (bPlaying == true) {
					//if event is keypressed
					inputManager.KeyPressed(event);
				}
			}

		}
		
		//SCENE HANDLING//
		//if in start screen
		if (bInMenu == true && bPlayed == false) {
			window.clear(sf::Color(255, 255, 255));
			//render
			menu.draw(window, 0);

		}
		//if was in game display win or loss
		else if (bInMenu == true && bPlayed == true)
		{
			window.clear(sf::Color(255, 255, 255));
			//if lost
			if (bWin == false)
			{
				menu.draw(window, 2);
				menu.setText(2, objects.ReturnFoodEaten());
			}

			//if won
			else if (bWin == true)
			{
				menu.draw(window, 1);
			}
		}

		//if game is playing display game
		//check if game is over
		if (bPlaying == true) {
			//slow down game by limiting frame rate so it updates at a slower speed to make it easier to play
			window.setFramerateLimit(difficulty * 4);
			//drawing
			objects.snakeMove();
			window.clear(sf::Color(255, 255, 255));
			objects.drawImageAll(window);
			if (objects.HasWon() == -1)
			{
				bPlaying = false;
				bInMenu = true;
				bPlayed = true;
				bWin = false;
				window.setFramerateLimit(30);
			}
			else if (objects.HasWon() == 1)
			{
				bPlaying = false;
				bInMenu = true;
				bPlayed = true;
				bWin = true;
				menu.setText(1, objects.ReturnTimer());
				window.setFramerateLimit(30);
			}
		}



		window.display();
	}
}