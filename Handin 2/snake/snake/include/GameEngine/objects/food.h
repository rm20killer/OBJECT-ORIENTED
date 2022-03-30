#pragma once
#include "DisplayManager.h"
class food
{
public:
	bool loadImage();
	void setPosition(sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	sf::Vector2f ReturnPosition();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int Direction = 1;
};