#include "../../../include/GameEngine/objects/wall.h"

bool Wall::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\texures\\wall.png")) return false;
	texture.setRepeated(true);
	leftWall.setTexture(texture);
	RightWall.setTexture(texture);
	bottomWall.setTexture(texture);
	topWall.setTexture(texture);

	leftWall.setTextureRect(sf::IntRect(0, 0, 50, 600));
	leftWall.setPosition(0, 0);

	RightWall.setTextureRect(sf::IntRect(0, 0, 50, 600));
	RightWall.setPosition(600, 0);

	topWall.setTextureRect(sf::IntRect(0, 0, 600, 50));
	topWall.setPosition(0, 0);

	bottomWall.setTextureRect(sf::IntRect(0, 0, 650, 50));
	bottomWall.setPosition(0, 600);
	return true;

}

void Wall::draw(sf::RenderWindow& window)
{
	window.draw(leftWall);
	window.draw(RightWall);
	window.draw(topWall);
	window.draw(bottomWall);
}

