#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Background
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& window);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	
};