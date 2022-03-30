#pragma once
#include "DisplayManager.h"
class food
{
public:
	bool loadImage();
	void setPosition();
	void draw(sf::RenderWindow& window);
	sf::Vector2f ReturnPosition();
private:
	sf::Sprite sprite;
	sf::Texture texture;
};