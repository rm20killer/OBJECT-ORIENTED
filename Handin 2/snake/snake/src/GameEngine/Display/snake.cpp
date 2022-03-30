#include "../../../include/GameEngine/objects/snake.h"
#include "../../../include/GameEngine/Events/GameOver.h"
#include "../../../include/GameEngine/objects/SnakeBody.h"

using namespace std;
/// <summary>
/// load texture from file and set it to a sprite while giving textures
/// </summary>
/// <returns>
/// false if loading failed
/// true if loaded
/// </returns>
bool SnakeHead::loadImage()
{
	//sf::Vector2f scale(50, 50);
	//load and set texture
	if (!texture.loadFromFile("..\.\\..\\assets\\texures\\snake.png")) return false;
	sprite.setTexture(texture);
	//set scale
	//sprite.setScale(scale.x,scale.y);
	sprite.setPosition(300, 300);
	for (int i = 0; i < MaxNumberOfBody; i++)
	{
		snakebody[i].loadImage();
	}
	return true;
}

void SnakeHead::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < NumberOfBody; i++)
	{
		snakebody[i].draw(window);
	}
	window.draw(sprite);
}

void SnakeHead::Move()
{
	for (int i = NumberOfBody; i >= 0; i=i-1)
	{
		if (i == 0)
		{
			snakebody[i].setPosition(sprite.getPosition());
		}
		else {
			snakebody[i].setPosition(snakebody[i - 1].ReturnPosition());
		}
	}
	//0 up, 1 left, 2 down 3 right
	if (Direction == 0)
	{
		if (sprite.getPosition().y > 0)
		{
			sprite.move(0, -50);
		}
		else
		{
			sprite.setPosition(300, 300);
			printf("GAME OVER\n");
		}
	}
	if (Direction == 1)
	{
		if (sprite.getPosition().x > 0)
		{
			sprite.move(-50, 0);
		}
		else 
		{
			sprite.setPosition(300, 300);
			printf("GAME OVER\n");
		}
	}
	if (Direction == 2)
	{
		if (sprite.getPosition().y < 600)
		{
			sprite.move(0, 50);
		}
		else
		{
			sprite.setPosition(300, 300);
			printf("GAME OVER\n");
		}
	}
	if (Direction == 3)
	{
		if (sprite.getPosition().x < 550)
		{
			sprite.move(50, 0);
		}
		else
		{
			sprite.setPosition(300, 300);
			printf("GAME OVER\n");
		}
	}
	for (int i = 0; i < NumberOfBody; i++)
	{
		if (sprite.getPosition() == snakebody[i].ReturnPosition()) {
			sprite.setPosition(300, 300);
			printf("GAME OVER\n");
		}
	}
}

void SnakeHead::Turn(int dir)
{
	Direction = dir;
}

sf::Vector2f SnakeHead::ReturnPosition()
{
	return sf::Vector2f(sprite.getPosition());
}
