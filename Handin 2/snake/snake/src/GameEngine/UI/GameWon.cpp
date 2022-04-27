
#include "..\..\..\include\GameEngine\UI\GameWon.h"

bool UIGameWon::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\UI\\YouWin.png")) return false;
	sprite.setTexture(texture);
	if (!font.loadFromFile("..\.\\..\\assets\\Fonts\\Quinquefive-0Wonv.ttf")) return false;
	text.setFont(font);
	//set text origin to center
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(400, 500);
	text.setCharacterSize(10);
	sprite.setPosition(0, 0);

	return true;
}

void UIGameWon::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(text);
}

void UIGameWon::SetText(std::string Timer)
{
	text.setString(Timer);
}