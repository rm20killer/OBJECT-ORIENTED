#pragma once
#include <SFML/Graphics.hpp>
class UIGameLost
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& window);
	void setText(int diff);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Font font;
	sf::Text text;
};