#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Ball
{
public:
	bool loadBall();
	void drawBall(sf::RenderWindow& window);
	void MoveBall(char direction, float velocity);

private:
	sf::Sprite spBall;
	sf::Texture texBall;
};