
#include "..\..\..\include\GameEngine\UI\InGame.h"
#include "..\..\..\include\GameEngine\Other\Timer.h"
Timer timer;
bool UIInGame::loadImage()
{
	timer.reset();
	if (!appleTexure.loadFromFile("..\.\\..\\assets\\texures\\food.png")) return false;
	appleSprite.setTexture(appleTexure);

	appleSprite.setPosition(650, 50);
	if (!font.loadFromFile("..\.\\..\\assets\\Fonts\\Quinquefive-0Wonv.ttf")) return false;
	text.setFont(font);
	text.setString("0");
	//set text origin to center
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(720, 60);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(25);

	timerText.setFont(font);
	timerText.setString("00:00");
	//set text origin to center
	timerText.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	timerText.setPosition(665, 20);
	timerText.setFillColor(sf::Color::Black);
	timerText.setCharacterSize(25);
	
	return true;

}

void UIInGame::draw(sf::RenderWindow& window)
{
	timer.update();	
	timerText.setString(timer.returnTime());
	window.draw(appleSprite);
	window.draw(text);
	window.draw(timerText);
}

void UIInGame::setText(int points)
{
	text.setString(std::to_string(points));
}

std::string UIInGame::returnTime()
{
	return timer.returnTime();
}