#include "../../../include/GameEngine/objects/ObjectManager.h"
#include "../../../include/GameEngine/objects/snake.h"
#include "../../../include/GameEngine/objects/Background.h"
#include "../../../include/GameEngine/objects/wall.h"
#include "..\..\..\include\GameEngine\objects\food.h"

SnakeHead snakehead;
Background background;
Wall wall;
//food Food;

/// <summary>
/// loads all textures used in the game.
/// </summary>
/// <returns>
/// false if loading failed
/// true all loaded
/// </returns>
bool Object::loadImageAll()
{
	if (snakehead.loadImage() == false) { return false; };
	if (background.loadImage() == false) { return false; };
	if (wall.loadImage() == false) { return false; };
	//if (Food.loadImage() == false) { return false; };
	//Food.setPosition();
	return true;
}

void Object::drawImageAll(sf::RenderWindow& window)
{
	//draw first (background)
	background.draw(window);
	wall.draw(window);
	snakehead.draw(window);
	//Food.setPosition();
	//Food.draw(window);

	//draw last (forground)
}

void Object::snakeMove()
{
	snakehead.Move();
}

void Object::snakeChangeDir(int Direction)
{
	snakehead.Turn(Direction);
}

int Object::HasWon()
{
	int isWon = snakehead.IsWon();
	if (isWon == 1)
	{
		printf("GAME WON\n");
	}
	else if (isWon == -1)
	{
		printf("GAME LOST\n");
	}
	else
	{
		
	}
	return isWon;
}