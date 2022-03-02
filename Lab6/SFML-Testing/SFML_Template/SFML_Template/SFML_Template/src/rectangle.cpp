#include<SFML/Graphics.hpp>
#include<iostream>
#include"../include/rectangle.h"

My_Rectangle::My_Rectangle(sf::Vector2f size)
{

	Rect.setSize(size);
	Rect.setPosition(200, 200);
	Rect.setFillColor(sf::Color::Magenta);

}

void My_Rectangle::drawTo(sf::RenderWindow& window)
{

	window.draw(Rect);
}