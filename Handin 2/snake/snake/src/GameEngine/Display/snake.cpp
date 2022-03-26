#include "../../../include/GameEngine/Display/snake.h"

/// <summary>
/// load texture from file and set it to a sprite while giving textures
/// </summary>
/// <returns>
/// false if loading failed
/// true if loaded
/// </returns>
bool SnakeHead::loadImage()
{
	sf::Vector2f scale(10, 10);
	//load and set texture
	if (!texture.loadFromFile(".\\.\\.\\assets\\texture\\snake.png")) return false;
	sprite.setTexture(texture);
	//set scale
	sprite.setScale(scale.x,scale.y);
	return true;
}

void SnakeHead::draw(sf::RenderWindow& renderer)
{
}
