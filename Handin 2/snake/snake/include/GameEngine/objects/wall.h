#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Wall
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& window);
private:
	sf::Sprite leftWall;
	sf::Sprite RightWall;
	sf::Sprite topWall;
	sf::Sprite bottomWall;
	sf::Texture texture;

};