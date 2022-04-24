#include "../../../include/GameEngine/objects/ObjectManager.h"
#include "../../../include/GameEngine/objects/snake.h"
#include "../../../include/GameEngine/objects/Background.h"
#include "../../../include/GameEngine/objects/wall.h"
#include "..\..\..\include\GameEngine\UI\InGame.h"
SnakeHead snakehead;
Background background;
Wall wall;
UIInGame UI;
//food Food;

/// <summary>
/// loads all textures used in the game.
/// </summary>
/// <returns>
/// false if loading failed
/// true if all loaded
/// </returns>
bool Object::loadImageAll()
{
	if (snakehead.loadImage() == false) { return false; };
	if (background.loadImage() == false) { return false; };
	if (wall.loadImage() == false) { return false; };
	if (UI.loadImage() == false) { return false; };
	//if (Food.loadImage() == false) { return false; };
	//Food.setPosition();
	return true;
}

/// <summary>
/// draw objects in the game
/// </summary>
/// <param name="window"></param>
void Object::drawImageAll(sf::RenderWindow& window)
{
	UI.setText(snakehead.ReturnFoodEaten());
	//draw first (background)
	background.draw(window);
	wall.draw(window);
	snakehead.draw(window);
	//Food.setPosition();
	//Food.draw(window);
	
	UI.draw(window);
	//draw last (forground)
}
/// <summary>
/// moves the snake
/// </summary>
void Object::snakeMove()
{
	snakehead.Move();
}
/// <summary>
/// change snake direction
/// </summary>
/// <param name="Direction"></param>
void Object::snakeChangeDir(int Direction)
{
	snakehead.Turn(Direction);
}
/// <summary>
/// check if the player has won or lost
/// </summary>
/// <returns></returns>
int Object::HasWon()
{
	int isWon = snakehead.IsWon();
	if (isWon == 1)
	{
		printf("GAME WON\n");
		//printf time
		printf("%s\n", UI.returnTime().c_str());
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

int Object::ReturnFoodEaten()
{
	return snakehead.ReturnFoodEaten();
}