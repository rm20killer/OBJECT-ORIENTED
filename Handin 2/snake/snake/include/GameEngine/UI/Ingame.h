#pragma once
#include <SFML/Graphics.hpp>
class UIInGame
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& window);
	void setText(int diff);
	std::string returnTime();
private:
	sf::Sprite appleSprite;
	sf::Texture appleTexure;
	sf::Font font;
	sf::Text text;
	sf::Text timerText;
};