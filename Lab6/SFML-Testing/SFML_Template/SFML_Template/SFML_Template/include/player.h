#pragma once

#include<iostream>
#include"SFML/Graphics.hpp"

class Player

{
private:

	sf::Texture mY_picture;
	sf::Sprite mY_Player;

	
	//sf::Texture mY_figure;
	//sf::Sprite mY_stone;               // This is to load second texture


public:

	Player();           // Default Constructor

	/*Player( std::string imgDirectory);*/     // This to use when you directly put the image beside the include and src folders in your project.


	Player(std::string Filename);
	
	void drawPlayer(sf::RenderWindow &window);

	void movePlayer(char direction, float motion);
			   		 	  


};