#include "../include/Stone.h"

bool stone::loadFloor()
{
	if (!tileTex.loadFromFile(".\\assets\\textures\\stone.png")) return false;
	tileTex.setRepeated(true);

	floor.setTexture(tileTex);
	floor.setTextureRect(sf::IntRect(0, 0, 800, 600));
	floor.setPosition(0, 0);
	return true;
}

void stone::drawFloor(sf::RenderWindow& window)
{
	window.draw(floor);
}
