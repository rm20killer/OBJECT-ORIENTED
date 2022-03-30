#include "..\..\..\include\GameEngine\objects\food.h"

bool food::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\texures\\food.png")) return false;
	sprite.setTexture(texture);
	return true;
}

/// <summary>
/// generates a random position for the food
/// </summary>
/// <param name="pos"></param>
void food::setPosition()
{
	int x = rand() % 11 + 1;
	int y = rand() % 11 + 1;
	sprite.setPosition(x * 50, y * 50);
}

void food::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

sf::Vector2f food::ReturnPosition()
{
	return sf::Vector2f(sprite.getPosition());
}

