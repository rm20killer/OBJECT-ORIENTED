#include "../../Lab6-SFML/Inlude/Gameplay.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Gameplay::Gameplay()
{
	myRectangle2.setSize(sf::Vector2f(50.f, 50.0f));
	myRectangle2.setOrigin(myRectangle2.getSize().x / 2.0f, myRectangle2.getSize().y / 2.0f);
	myRectangle2.setPosition(iRectangleX, iRectangleY);
	myRectangle2.setOutlineColor(sf::Color::Black);
	myRectangle2.setFillColor(sf::Color::Red);
	myRectangle2.setOutlineThickness(1.0f);

	myCircle.setRadius(50.f);
	myCircle.setOrigin(myCircle.getRadius() / 2, myCircle.getRadius() / 2);
	myCircle.setPosition(400, 400);
	myCircle.setOutlineColor(sf::Color::Black);
	myCircle.setFillColor(sf::Color::Red);
	myCircle.setOutlineThickness(1.0f);
}


void Gameplay::movableCube(char direction, float velocity)
{
	int iRed = (rand() % 255);
	int iBlue = (rand() % 255);
	int iGreen = (rand() % 255);
	//sf::Color test(iRed, iBlue, iGreen , 0);
	myRectangle2.setFillColor(sf::Color(iRed, iBlue, iGreen, 255));
	if (direction == 'w') {
		if (myRectangle2.getPosition().y > 40){
			if (myRectangle2.getLocalBounds().intersects(myCircle.getGlobalBounds())) {
				printf("Has hit circle");
			}
			else {
				myRectangle2.move(0, -velocity);
			}
		}
	}
	if (direction == 's') {
		if (myRectangle2.getPosition().y < iSizey) {
			if (myRectangle2.getLocalBounds().intersects(myCircle.getGlobalBounds())) {
				printf("Has hit circle");
			}
			else {
				myRectangle2.move(0, velocity);
			}
		}
	}
	if (direction == 'a') {
		if (myRectangle2.getPosition().x > 40) {
			if (myRectangle2.getLocalBounds().intersects(myCircle.getGlobalBounds())) {
				printf("Has hit circle");
			}
			else {
				myRectangle2.move(-velocity, 0);
			}
		}
	}
	if (direction == 'd') {
		if (myRectangle2.getPosition().x < iSizex) {
			if (myRectangle2.getLocalBounds().intersects(myCircle.getGlobalBounds())) {
				printf("Has hit circle");
			}
			else {
				myRectangle2.move(velocity, 0);
			}
		}
	}
}

void Gameplay::drawCube(sf::RenderWindow& window)
{
	window.draw(myRectangle2);
	window.draw(myCircle);
}

void Gameplay::setScreenSize(int inSizex, int inSizey)
{
	iSizex = inSizex-40;
	iSizey = inSizey-40;
}
