#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Text
{
public:
	bool loadFonts();
	void LoadText();
	void DisplayText(sf::RenderWindow& window);
	void updateText(int i);
private:
	sf::Font digitalFont;
	sf::Text scoreLabel;
	sf::Text scoreText;
};