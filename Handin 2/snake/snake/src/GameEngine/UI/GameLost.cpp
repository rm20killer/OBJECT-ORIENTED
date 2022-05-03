 
#include "..\..\..\include\GameEngine\UI\GameLost.h"

bool UIGameLost::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\UI\\YouLost.png")) return false;
	sprite.setTexture(texture);
	sprite.setPosition(0, 0);
	//load font
	if (!font.loadFromFile("..\.\\..\\assets\\Fonts\\Quinquefive-0Wonv.ttf")) return false;
	text.setFont(font);
	text.setString("");
	//set text origin to center
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(400, 500);
	text.setCharacterSize(10);

	return true;
}

void UIGameLost::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(text);
}
void UIGameLost::setText(int score)
{
	text.setString("Points: " + std::to_string(score)+ "/5");
}