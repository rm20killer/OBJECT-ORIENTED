#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/GameEngine/Input/InputManager.h"
#include "../include/GameEngine/Display/DisplayManager.h"

using namespace std;

//#varibles#//

//window varibles
int ScreenWidth = 800;
int ScreenHeight = 600;

InputManager inputManager;
Object objects;

int main() {
	//load in images and sou
	objects.loadImageAll();
	//render window
	sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), "Snake");
	window.setFramerateLimit(60);
	
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
		//drawing
		objects.drawImageAll(window);
		window.display();
	}
}