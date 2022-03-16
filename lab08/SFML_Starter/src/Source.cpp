#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Stone.h"
#include "../include/ball.h"
#include "../include/Audio.h"
#include "../include/Text.h"

using namespace std;

stone Stone;
Ball ball;
audio Audio;
Text text;

int moved = 0;


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
	sf::RenderWindow window(sf::VideoMode(800, 600), "Ball on stone");

	window.setPosition(sf::Vector2i(100, 100)); // Set the position of the window to 100,100
	Stone.loadFloor();
	ball.loadBall();
	window.setFramerateLimit(0); // Set the limit of the the number of frames per second
	Audio.LoadAudio();
	text.loadFonts();
	text.LoadText();

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
					moved++;
					char direction = 'w';
					ball.MoveBall(direction, 10);
					text.updateText(moved);
					//myRectangle2.move(0, -10);
				}
				if (event.key.code == sf::Keyboard::S) {
					moved++;
					char direction = 's';
					//myRectangle2.move(0, 10);
					ball.MoveBall(direction, 10);
					text.updateText(moved);
				}
				if (event.key.code == sf::Keyboard::A) {
					moved++;
					char direction = 'a';
					//myRectangle2.move(-10, 0);
					ball.MoveBall(direction, 10);
					text.updateText(moved);
				}
				if (event.key.code == sf::Keyboard::D) {
					moved++;
					char direction = 'd';
					//myRectangle2.move(10, 0);
					ball.MoveBall(direction, 10);
					text.updateText(moved);
				}
				ball.drawBall(window);
				Audio.UpdateAudio(float(moved));
				Audio.playAudio();
			}
		}
		window.clear(sf::Color(255, 255, 255));
		Stone.drawFloor(window);
		ball.drawBall(window);
		text.DisplayText(window);
		window.display();
	}
}