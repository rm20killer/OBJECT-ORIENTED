#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/GameEngine/Input/InputManager.h"
#include "../include/GameEngine/objects/ObjectManager.h"
#include "../include/GameEngine/objects/snake.h"
using namespace std;

//#varibles#//

//window varibles
int ScreenWidth = 800;
int ScreenHeight = 650;

InputManager inputManager;
Object objects;
SnakeHead snakeHead;
int main() {
	//load in images and sou
	objects.loadImageAll();
	//render window
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Snake");
	window.setFramerateLimit(4);
	
	//window open
	while (window.isOpen()) {
		//event loop
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
			//if event is keypressed
			if (event.type == sf::Event::KeyPressed) {
				inputManager.KeyPressed(event);
			}
		}
		//drawing~
		objects.snakeMove();
		window.clear(sf::Color(255, 255, 255));
		objects.drawImageAll(window);
		window.display();
	}
}