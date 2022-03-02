/*
#include "..\Inlude\shape.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
float iRectangleX = 0;
float iRectangleY = 0;

int fSizex = 800;
int fSizey = 600;

int iRed = 0;
int iBlue = 0;
int iGreen = 0;
int alpha = 255;

void shape::DrawBricks(sf::RenderWindow &window)
{
	sf::RectangleShape myRectangle;
	myRectangle.setSize(sf::Vector2f(50.f, 50.0f));
	myRectangle.setOrigin(myRectangle.getSize().x/2.0f, myRectangle.getSize().y/2.0f);
	myRectangle.setPosition(iRectangleX, iRectangleY);
	myRectangle.setOutlineColor(sf::Color::Black);
	myRectangle.setFillColor(sf::Color::Red);
	myRectangle.setOutlineThickness(1.0f);
	while (iRectangleY < fSizey + 500) {
		if (iRectangleX < fSizex + 200) {
			int iRed = (rand() % 255);
			int iBlue = (rand() % 255);
			int iGreen = (rand() % 255);
			myRectangle.setFillColor(sf::Color(iRed, iBlue, iGreen, 255));
			window.draw(myRectangle);
			iRectangleX = iRectangleX + 10;
			myRectangle.setPosition(iRectangleX, iRectangleY);
		}
		else
		{
			iRectangleY = iRectangleY + 10;
			iRectangleX = 0;
		}
		window.display();
	}
}
*/