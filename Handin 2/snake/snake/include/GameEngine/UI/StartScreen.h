#pragma once
#include <SFML/Graphics.hpp>
class UIStartScreen
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& window);
private:
	sf::Sprite sprite;
	sf::Texture texture;
};