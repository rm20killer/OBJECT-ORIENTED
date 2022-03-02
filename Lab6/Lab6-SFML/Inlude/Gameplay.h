#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once

class Gameplay
{
public:
	Gameplay();
	void movableCube(char direction, float velocity);
	void drawCube(sf::RenderWindow& window);
	void setScreenSize(int iSizex, int iSizey);
private:
	float iRectangleX = 200;
	float iRectangleY = 200;
	int iSizex = 0;
	int iSizey = 0;
	sf::RectangleShape myRectangle2;
	sf::CircleShape myCircle;
	//sf::RenderWindow& m_window;
};
