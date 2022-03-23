#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Ball
{
public:
	bool loadBall();
	void drawBall(sf::RenderWindow& window);
	void MoveBall(char direction, float velocity);
	int idleAnimation(int iCurrentFrame);

private:
	sf::Sprite spBall;
	sf::Texture texBall;

	sf::Texture IdleTex;
	sf::Sprite IdleSprite;
	static const int iNumFrames = 9;
	sf::IntRect IdleRects[iNumFrames];
};