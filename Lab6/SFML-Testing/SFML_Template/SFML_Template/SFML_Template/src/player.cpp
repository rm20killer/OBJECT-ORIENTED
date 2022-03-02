#include <SFML/Graphics.hpp>
#include"../include/player.h"
#include<iostream>

Player::Player()
{

};


Player::Player(std::string Filename)
{
	if (!mY_picture.loadFromFile(".\\assets\\textures\\" + Filename))
	{

		std::cout << "Texture not found \n";
	}

	mY_Player.setTexture(mY_picture);
	mY_Player.scale(sf::Vector2f(0.2f, 0.2f));
	mY_Player.setOrigin(60.0f, 60.0f);
	mY_Player.setPosition(200.f, 300.f);
	mY_Player.setColor(sf::Color(255, 255, 255, 128));



	//if (!mY_figure.loadFromFile(".\\assets\\textures\\" + Filename)) {

	//	///*mY_stone.scale(sf::Vector2f(1, 1));
	//	//mY_stone.setOrigin(sf::Vector2f(0, 0));
	//	//mY_stone*/.setPosition(sf::Vector2f(100, 100));

	//	mY_stone.setTexture(mY_figure);


	//}

}



//------------------------------------------------------------------------------------
//Player::Player( std::string imgDirectory)
//{
//	if (!mY_picture.loadFromFile(imgDirectory))
//	{
//
//		std::cout<<"Texture not found \n";             // To use when you do not put image in the asset folder and direclty put the .png file beside your include and src folder.
//	}
//
//	mY_Player.setTexture(mY_picture);
//
//}
//------------------------------------------------------------------------------------

void Player::drawPlayer(sf::RenderWindow &window) // drawing the sprite
{

	window.draw(mY_Player);

}

void Player::movePlayer(char direction, float motion)  // moving the sprite
{


	if (direction == 'u')
	{

		mY_Player.move(0, -motion);
	}
	else if(direction == 'd')

	{
		mY_Player.move(0, motion);
	}
	else if (direction == 'l')
	{

		mY_Player.move( -motion, 0);

	}
	else if (direction == 'r')
	{

		mY_Player.move(motion, 0);

	}
	   	  

}