#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>


class DisplayManager
{

};
class Object 
{
public:
	bool loadImageAll();
	void drawImageAll(sf::RenderWindow& window);
	void snakeMove();
	void snakeChangeDir(int Direction);
};