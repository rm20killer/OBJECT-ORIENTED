#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/GameEngine/Input/InputManager.h"
#include "../include/GameEngine/objects/ObjectManager.h"
#include "../include/GameEngine/objects/snake.h"
#include "../include/GameEngine/UI/UiManager.h"

using namespace std;

//#varibles#//

//window varibles
int ScreenWidth = 800;
int ScreenHeight = 650;
bool bPlaying = false;
bool bInMenu = true;
int difficulty = 1;
InputManager inputManager;
Object objects;
Menu menu;
int main() {
	//load in images and sou
	//objects.loadImageAll();
	//render window
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Snake");
	window.setFramerateLimit(4);
	menu.loadAllImages();
	//window open
	while (window.isOpen()) {
		//event loop
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
			if (bInMenu == true) {
				if(event.type == sf::Event::KeyPressed) {
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
					printf("%i \n",difficulty);
				}
			}
			//if game is playing
			if (bPlaying == true) {
				//if event is keypressed
				if (event.type == sf::Event::KeyPressed) {
					inputManager.KeyPressed(event);
				}
			}
		}
		if (bInMenu == true) {
			window.clear(sf::Color(255, 255, 255));
			//render
			menu.draw(window,0);

		}
		
		//if game is playing
		if (bPlaying == true) {
			window.setFramerateLimit(difficulty * 4);
			//drawing
			objects.snakeMove();
			window.clear(sf::Color(255, 255, 255));
			objects.drawImageAll(window);
			if (objects.HasWon() == -1)
			{
				bPlaying = false;
				bInMenu = true;
			}
			else if (objects.HasWon() == 1)
			{
				bPlaying = false;
				bInMenu = true;
				//window.setFramerateLimit(30);
			}
		}



		window.display();
	}
}