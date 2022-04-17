
#include "..\..\..\include\GameEngine\UI\StartScreen.h"

bool UIStartScreen::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\UI\\test.png")) return false;
	sprite.setTexture(texture);

	sprite.setPosition(0, 0);
	return true;
}

void UIStartScreen::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}