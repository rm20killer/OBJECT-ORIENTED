
#include "..\..\..\include\GameEngine\UI\GameWon.h"

bool UIGameWon::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\UI\\YouWin.png")) return false;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);

	return true;
}

void UIGameWon::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}