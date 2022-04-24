#include "..\..\..\include\GameEngine\objects\SnakeBody.h"

bool SnakeBody::loadImage()
{
	sf::Vector2f IdleSize(50, 50);
	const sf::Vector2i sheetDims(4, 1);
	if (!texture.loadFromFile("..\.\\..\\assets\\texures\\snakeBody_spritesheet.png")) return false;
	sprite.setTexture(texture);
	for (int i = 0; i < sheetDims.x; i++)
	{
		for (int j = 0; j < sheetDims.y; j++)
		{
			Rects[i + j * 3] = sf::IntRect(i * IdleSize.x, j * IdleSize.y, IdleSize.x, IdleSize.y);
		}
	}
	sprite.setScale(IdleSize.x / texture.getSize().x * sheetDims.x, IdleSize.y / texture.getSize().y * sheetDims.y);
	sprite.setTexture(texture);
	sprite.setTextureRect(Rects[iNumFrames]);
	sprite.setOrigin(0, 0);
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

void SnakeBody::setRotation(int i)
{
	sprite.setTextureRect(Rects[i]);
}

