#pragma once
#include "SnakeBody.h"
class SnakeHead
{
public:
	bool loadImage();
	void draw(sf::RenderWindow& window);

	void Move();
	void Turn(int dir);
	sf::Vector2f ReturnPosition();
	int IsWon();
private:
	sf::Sprite sprite;
	sf::Texture texture;
	int Direction=1;
	//0 up, 1 left, 2 down 3 right
	int WinAmount = 5;
	bool bIsLost = false;
	int iHitBypass = 0;
protected:
	static const int MaxNumberOfBody = 10;
	int NumberOfBody =3;

	//SnakeBody snakebody1;
	SnakeBody snakebody[MaxNumberOfBody];
};