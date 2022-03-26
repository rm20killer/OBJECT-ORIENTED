#include "../../../include/GameEngine/Display/DisplayManager.h"
#include "../../../include/GameEngine/Display/snake.h"
#include "../../../include/GameEngine/Display/Background.h"


SnakeHead snakehead;
Background background;
/// <summary>
/// loads all textures used in the game.
/// </summary>
/// <returns>
/// false if loading failed
/// true all loaded
/// </returns>
bool Object::loadImageAll()
{
	//if (snakehead.loadImage() == false) { return false; };
	if (background.loadImage() == false) { return false; };
	return true;
}

void Object::drawImageAll(sf::RenderWindow& window)
{
	//snakehead.draw(window);
	background.draw(window);
}
