#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Menu
{
public:
	bool loadAllImages();
	void draw(sf::RenderWindow& window, int Menu);
	void setText(int iMenuType, int iInput);
};