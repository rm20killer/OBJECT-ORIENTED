#pragma once
#include "ObjectManager.h"
class food
{
public:
	bool loadImage();
	sf::Vector2f generateRandomPosition();
	void setPosition(sf::Vector2f pos);
	void setPosition();
	void draw(sf::RenderWindow& window);
	sf::Vector2f ReturnPosition();
private:
	sf::Sprite sprite;
	sf::Texture texture;
};