#pragma once
#include <SFML/Graphics.hpp>
class UIStartScreen
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& window);
	void setDiff(int diff);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Font font;
	sf::Text text;
	sf::Text text2;
};