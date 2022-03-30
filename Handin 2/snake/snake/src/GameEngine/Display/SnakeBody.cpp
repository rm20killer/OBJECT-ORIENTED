#include "..\..\..\include\GameEngine\objects\SnakeBody.h"

bool SnakeBody::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\texures\\snake.png")) return false;
	sprite.setTexture(texture);

	sprite.setPosition(300,300);
	return true;
}

void SnakeBody::setPosition(sf::Vector2f pos)
{
	sprite.setPosition(pos);
}

void SnakeBody::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

sf::Vector2f SnakeBody::ReturnPosition()
{
	return sf::Vector2f(sprite.getPosition());
}

