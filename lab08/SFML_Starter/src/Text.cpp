#include "../include/Text.h"

bool Text::loadFonts()
{
	if (!digitalFont.loadFromFile(".\\assets\\fonts\\DIGITALDREAMFATSKEW.TTF")) return 0;
}

void Text::LoadText()
{
	scoreLabel.setFont(digitalFont);
	scoreLabel.setString("Moved:");
	scoreLabel.setCharacterSize(16);
	scoreLabel.setPosition(0, 0);
	scoreLabel.setFillColor(sf::Color::White);

	scoreText.setFont(digitalFont);
	scoreText.setString("0");
	scoreText.setCharacterSize(16);
	scoreText.setPosition(80, 0);
	scoreText.setFillColor(sf::Color::Red);

}

void Text::DisplayText(sf::RenderWindow& window)
{
	window.draw(scoreLabel);
	window.draw(scoreText);
}

void Text::updateText(int i)
{
	scoreText.setString(std::to_string(i));
}

