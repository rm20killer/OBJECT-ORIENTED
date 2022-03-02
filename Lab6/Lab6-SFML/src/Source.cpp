#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../Lab6-SFML/Inlude/Gameplay.h"

using namespace std;

float iRectangleX = 200;
float iRectangleY = 200;

int iSizex = 800;
int iSizey = 600;

int iRed = 0;
int iBlue = 0;
int iGreen = 0;
int alpha = 255;
int main()
{
	//window maker
	sf::RenderWindow window(sf::VideoMode(iSizex, iSizey), "New window");
	window.setPosition(sf::Vector2i(100, 100));
	window.setFramerateLimit(30);
	
	//Timer
	sf::Clock Timer;
	int iCounter = 0;
	float lastTime = 0;

	//shape (rectangle)
	
	Gameplay gameplay;
	sf::RectangleShape myRectangle;
	myRectangle.setSize(sf::Vector2f(800-38, 600- 38));
	myRectangle.setOrigin(0,0);
	myRectangle.setPosition(20, 20);
	myRectangle.setOutlineColor(sf::Color::Black);
	myRectangle.setFillColor(sf::Color(255, 255, 255, 255));
	myRectangle.setOutlineThickness(20.0f);
	while (window.isOpen())
	{
		sf::Event event;
		gameplay.setScreenSize(iSizex, iSizey);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				window.clear(sf::Color::White);
				int iRed = (rand() % 255);
				int iBlue = (rand() % 255);
				int iGreen =(rand() % 255);
				//sf::Color test(iRed, iBlue, iGreen , 0);
				//myRectangle.setFillColor(sf::Color(iRed, iBlue, iGreen, 255));
				//myRectangle.setOutlineColor(sf::Color(iRed, iBlue, iGreen,255));
				//up down
				if (event.key.code == sf::Keyboard::W) {
					char direction = 'w';
					gameplay.movableCube(direction, 10);
					//myRectangle2.move(0, -10);
				}
				if (event.key.code == sf::Keyboard::S) {
					char direction = 's';
					//myRectangle2.move(0, 10);
					gameplay.movableCube(direction, 10);
				}
				if (event.key.code == sf::Keyboard::A) {
					char direction = 'a';
					//myRectangle2.move(-10, 0);
					gameplay.movableCube(direction, 10);
				}
				if (event.key.code == sf::Keyboard::D) {
					char direction = 'd';
					//myRectangle2.move(10, 0);
					gameplay.movableCube(direction, 10);
				}
				window.draw(myRectangle);
				gameplay.drawCube(window);
				//window.draw(myRectangle2);
				window.display();
			}
		}
		sf::Time elapsedTime = Timer.getElapsedTime();
		if (elapsedTime.asSeconds() > 1.0f)
		{
			//printf("%i \n", iCounter);
			//iCounter++;
			//if (iCounter == 100)
			//{
			//	iCounter = 0;
			//}
		}
		//system("pause");
		//return 0;
	}
}