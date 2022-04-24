#include "..\..\..\include\GameEngine\objects\food.h"
#include "../../../include/GameEngine/objects/snake.h"
#include "../../../include/GameEngine/objects/SnakeBody.h"
bool food::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\texures\\food.png")) return false;
	sprite.setTexture(texture);
	return true;
}


/// <summary>
/// generate a random position for the food
/// </summary>
/// <returns> Vector2F</returns>
sf::Vector2f food::generateRandomPosition()
{
	int x = rand() % 11 + 1;
	int y = rand() % 11 + 1;
	x = x * 50;
	y = y * 50;
	printf("generate post at %i,%i\n", x, y);
	return sf::Vector2f(x,y);
}
/// <summary>
/// set the position of the food based on a given position
/// </summary>
/// <param name="pos"></param>
void food::setPosition(sf::Vector2f pos)
{
	printf("Position set at %f,%f\n", pos.x, pos.y);
	sprite.setPosition(pos);
}
/// <summary>
/// set the position of the food based on a random position
/// </summary>
void food::setPosition()
{
	int x = rand() % 11 + 1;
	int y = rand() % 11 + 1;
	sprite.setPosition(x * 50, y * 50);
	//printf x and y
	printf("x: %i, y: %i\n", x, y);
}

void food::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

/// <summary>
///	return position
/// </summary>
/// <returns> Vector2f </returns>
sf::Vector2f food::ReturnPosition()
{
	return sf::Vector2f(sprite.getPosition());
}

