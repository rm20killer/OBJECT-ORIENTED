#include "../include/ball.h"

bool Ball::loadBall()
{
	if (!texBall.loadFromFile(".\\assets\\textures\\beachball.png")) return false;
	
	spBall.setTexture(texBall);
	spBall.setPosition(100, 100);
	spBall.setScale(0.25f, 0.25f);

	sf::Vector2f IdleSize(286, 263);
	const sf::Vector2i sheetDims(3, 3);
	if (!IdleTex.loadFromFile(".\\assets\\textures\\bird.png")) return false;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			IdleRects[i + j * 3] = sf::IntRect(i * IdleSize.x, j * IdleSize.y, IdleSize.x, IdleSize.y);
		}
	}
	IdleSprite.setScale(IdleSize.x / IdleTex.getSize().x * sheetDims.x, IdleSize.y / IdleTex.getSize().y * sheetDims.y);
	IdleSprite.setOrigin(IdleSize.x / 2.f / IdleSprite.getScale().x, IdleSize.y / 2.f / IdleSprite.getScale().y);
	IdleSprite.setTexture(IdleTex);
	IdleSprite.setTextureRect(IdleRects[iNumFrames]);

	
	
	return true;
}

void Ball::drawBall(sf::RenderWindow& window)
{
	window.draw(IdleSprite);
}

void Ball::MoveBall(char direction, float velocity)
{
	if (direction == 'w') {
		if (IdleSprite.getPosition().y > 0) {
			IdleSprite.move(0, -velocity);
		}
	}
	if (direction == 's') {
		if (IdleSprite.getPosition().y < 500) {
			IdleSprite.move(0, velocity);
			//spBall.move(-velocity, 0);
		}
	}
	if (direction == 'a') {
		if (IdleSprite.getPosition().x > 0) {
			IdleSprite.move(-velocity, 0);
		}
	}
	if (direction == 'd') {
		if (IdleSprite.getPosition().x < 700) {
			IdleSprite.move(velocity, 0);
		}
	}
}

int Ball::idleAnimation(int iCurrentFrame)
{
	iCurrentFrame++;
	if (iCurrentFrame > iNumFrames)
	{
		iCurrentFrame = 0;
	}
	IdleSprite.setTextureRect(IdleRects[iCurrentFrame]);
	return iCurrentFrame;
}

//void Ball::drawBird(sf::RenderWindow& window)
//{
//	window.draw(IdleSprite);
//}
