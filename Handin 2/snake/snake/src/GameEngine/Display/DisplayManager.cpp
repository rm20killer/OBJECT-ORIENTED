#include "../../../include/GameEngine/objects/DisplayManager.h"
#include "../../../include/GameEngine/objects/snake.h"
#include "../../../include/GameEngine/objects/Background.h"
#include "../../../include/GameEngine/objects/wall.h"

SnakeHead snakehead;
Background background;
Wall wall;

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
	return true;
}

void Object::drawImageAll(sf::RenderWindow& window)
{
	//draw first (background)
	background.draw(window);
	wall.draw(window);
	snakehead.draw(window);

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
