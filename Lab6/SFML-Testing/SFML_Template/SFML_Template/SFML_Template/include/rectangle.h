#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>

class My_Rectangle
{
public:
	My_Rectangle(sf::Vector2f size);
	void drawTo(sf::RenderWindow& window);



private:


	sf::RectangleShape Rect;



};
