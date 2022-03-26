#pragma once
#include "DisplayManager.h"
class SnakeHead
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& renderer);
private:
	sf::Sprite sprite;
	sf::Texture texture;
};