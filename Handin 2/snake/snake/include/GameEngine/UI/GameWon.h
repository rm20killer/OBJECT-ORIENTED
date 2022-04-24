#pragma once
#include <SFML/Graphics.hpp>
class UIGameWon
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& window);
private:
	sf::Sprite sprite;
	sf::Texture texture;
};