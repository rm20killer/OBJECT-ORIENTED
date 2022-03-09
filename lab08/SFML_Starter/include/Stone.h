#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class stone
{
public:
	bool loadFloor();
	void drawFloor(sf::RenderWindow& window);

private:
	sf::Sprite floor;
	sf::Texture tileTex;
};