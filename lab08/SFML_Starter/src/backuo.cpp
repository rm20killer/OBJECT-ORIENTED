#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Stone.h"
#include "../include/ball.h"

using namespace std;

stone Stone;
Ball ball;

bool loadTextures(sf::Texture& tex, string sFileName)
{
	bool bSuccess;
	bSuccess = tex.loadFromFile(".\\assets\\textures\\" + sFileName);
	if (!bSuccess)
	{
		return false;
	}
	return true;
}
int main()
{
	// Create a window with the constructor
	sf::RenderWindow window(sf::VideoMode(800, 600), "My first SFML window");

	window.setPosition(sf::Vector2i(100, 100)); // Set the position of the window to 100,100
	Stone.loadFloor();
	ball.loadBall();
	window.setFramerateLimit(60); // Set the limit of the the number of frames per second

	bool bIsUpPressed = false;
	bool bIsLeftPressed = false;

	sf::Clock timer; // A timer object
	int iCounter = 0; // An interger for counting

					  // Run until the user closes the window
	while (window.isOpen())
	{
		// check all user events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// User has pressed the close button
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W) {
					char direction = 'w';
					ball.MoveBall(direction, 10);
					//myRectangle2.move(0, -10);
				}
				if (event.key.code == sf::Keyboard::S) {
					char direction = 's';
					//myRectangle2.move(0, 10);
					ball.MoveBall(direction, 10);
				}
				if (event.key.code == sf::Keyboard::A) {
					char direction = 'a';
					//myRectangle2.move(-10, 0);
					ball.MoveBall(direction, 10);
				}
				if (event.key.code == sf::Keyboard::D) {
					char direction = 'd';
					//myRectangle2.move(10, 0);
					ball.MoveBall(direction, 10);
				}
				ball.drawBall(window);
			}
		}
		window.clear(sf::Color(255, 255, 255));
		Stone.drawFloor(window);
		ball.drawBall(window);
		window.display();
	}
}