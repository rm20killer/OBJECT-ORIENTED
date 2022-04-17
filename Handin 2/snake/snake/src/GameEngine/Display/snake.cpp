#include "../../../include/GameEngine/objects/snake.h"
#include "../../../include/GameEngine/Events/GameOver.h"
#include "../../../include/GameEngine/objects/SnakeBody.h"
#include "..\..\..\include\GameEngine\objects\food.h"

using namespace std;


food Food;
/// <summary>
/// load texture from file and set it to a sprite while giving textures
/// </summary>
/// <returns>
/// false if loading failed
/// true if loaded
/// </returns>
bool SnakeHead::loadImage()
{
	NumberOfBody = 3;
	bIsLost = false;
	if (Food.loadImage() == false) { return false; };
	Food.setPosition();
	//sf::Vector2f scale(50, 50);
	//load and set texture
	if (!texture.loadFromFile("..\..\\..\\assets\\texures\\snake.png")) return false;
	sprite.setTexture(texture);
	//set scale
	//sprite.setScale(scale.x,scale.y);
	sprite.setPosition(300, 300);
	for (int i = 0; i < MaxNumberOfBody; i++)
	{
		snakebody[i].loadImage();
	}
	Food.setPosition();
	return true;
}

void SnakeHead::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < NumberOfBody; i++)
	{
		snakebody[i].draw(window);
	}
	window.draw(sprite);
	Food.draw(window);
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
		if (sprite.getPosition().y > 50)
		{
			sprite.move(0, -50);
		}
		else
		{
			bIsLost = true;
			//sprite.setPosition(300, 300);
		}
	}
	if (Direction == 1)
	{
		if (sprite.getPosition().x > 50)
		{
			sprite.move(-50, 0);
		}
		else 
		{
			bIsLost = true;			
			//sprite.setPosition(300, 300);
		}
	}
	if (Direction == 2)
	{
		if (sprite.getPosition().y < 550)
		{
			sprite.move(0, 50);
		}
		else
		{
			bIsLost = true;			
			//sprite.setPosition(300, 300);
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
			bIsLost = true;
			//sprite.setPosition(300, 300);
		}
	}
	//	iHitBypass = 0;
	for (int i = 0; i < NumberOfBody; i++)
	{
		if (sprite.getPosition() == snakebody[i].ReturnPosition()) {
			bIsLost = true;
			//sprite.setPosition(300, 300);
		}
	}
	//if collided with food
	if (sprite.getPosition() == Food.ReturnPosition())
	{
		Food.setPosition();
		if (MaxNumberOfBody-1>NumberOfBody) //5 points
		{
			NumberOfBody++;
			printf ("%i\n", NumberOfBody);
		}
		else {
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


int SnakeHead::IsWon()
{
	if (MaxNumberOfBody - 2 <= NumberOfBody) //5 points
	{
		return 1;
	}
	else {
		if(bIsLost == true){
			return -1;
		}
		else {
			return 0;
		}
	}
}