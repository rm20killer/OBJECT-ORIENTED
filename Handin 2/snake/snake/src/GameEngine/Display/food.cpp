#include "..\..\..\include\GameEngine\objects\food.h"

bool food::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\texures\\food.png")) return false;
	sprite.setTexture(texture);
	return true;
}

void food::setPosition(sf::Vector2f pos)
{
	//random number from 1 to 11 then multiple that by 50

	//user random number 1 and random number 2 to set posistion of sprite
}

void food::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

sf::Vector2f food::ReturnPosition()
{
	return sf::Vector2f(sprite.getPosition());
}
