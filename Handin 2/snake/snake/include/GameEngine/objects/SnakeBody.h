#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class SnakeBody
{
public:
	bool loadImage();
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	sf::Vector2f ReturnPosition();
	void setRotation(int i);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int Direction = 1;
	static const int iNumFrames = 4;
	sf::IntRect Rects[iNumFrames];
};