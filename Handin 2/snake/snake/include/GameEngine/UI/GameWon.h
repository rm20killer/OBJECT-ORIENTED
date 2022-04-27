#pragma once
#include <SFML/Graphics.hpp>
class UIGameWon
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& window);
	void SetText(std::string Timer);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Font font;
	sf::Text text;
};