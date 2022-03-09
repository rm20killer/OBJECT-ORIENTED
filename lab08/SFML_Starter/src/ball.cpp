#include "../include/ball.h"

bool Ball::loadBall()
{
	if (!texBall.loadFromFile(".\\assets\\textures\\beachball.png")) return false;
	
	spBall.setTexture(texBall);
	spBall.setPosition(100, 100);
	spBall.setScale(0.25f, 0.25f);
	return true;
}

void Ball::drawBall(sf::RenderWindow& window)
{
	window.draw(spBall);
}

void Ball::MoveBall(char direction, float velocity)
{
	if (direction == 'w') {
		if (spBall.getPosition().y > 0) {
			spBall.move(0, -velocity);
		}
	}
	if (direction == 's') {
		if (spBall.getPosition().y < 500) {
			spBall.move(0, velocity);
			//spBall.move(-velocity, 0);
		}
	}
	if (direction == 'a') {
		if (spBall.getPosition().x > 0) {
			spBall.move(-velocity, 0);
		}
	}
	if (direction == 'd') {
		if (spBall.getPosition().x < 700) {
			spBall.move(velocity, 0);
		}
	}
}
