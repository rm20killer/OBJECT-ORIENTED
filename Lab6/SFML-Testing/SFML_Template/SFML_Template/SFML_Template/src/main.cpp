#include <SFML/Graphics.hpp>
#include <iostream>
#include"../include/player.h"
#include"../include/ui.h"
#include"../include/rectangle.h"

//using namespace std;
using namespace std;

int main()
{
	// Create a window with the constructor
	//sf::RenderWindow window(sf::VideoMode(800, 600), "My first SFML window");
	sf::RenderWindow window(sf::VideoMode(1024, 1024), "Smaller window.", sf::Style::Default);

	
	window.setPosition(sf::Vector2i(100, 100)); // Set the position of the window to 100,100 relative to the desktop.

	window.setFramerateLimit(60); // Set the limit of the the number of frames per second

	window.setKeyRepeatEnabled(true);
	

	
	UI ui;
	ui.setTextString("Move the tiled player");
	
	
	Player mY_Player ("stone.png");


	My_Rectangle Player2({40.f, 80.f});
	

	



	
	//Player mY_Play("lights.png");

	/*bool bIsUpPressed = false;
	bool bIsLeftPressed = false;*/



	sf::Clock timer; // A timer object
	int iCounter = 0; // An interger for counting

					  // Run until the user closes the window
	while (window.isOpen())
	{
		// check all user events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// User has pressed the close button
			if (event.type == sf::Event::Closed)
			{
				window.close();

			}
			
			// Process any keypresses
			if (event.type == sf::Event::KeyPressed)
			{

				if (event.key.code == sf::Keyboard::Up) mY_Player.movePlayer('u', 10); // move Player 10 pixels up
				if (event.key.code == sf::Keyboard::Down) mY_Player.movePlayer('d', 10); // move Player 10 pixels down
				if (event.key.code == sf::Keyboard::Left) mY_Player.movePlayer('l', 10); // move Player 10 pixels left
				if (event.key.code == sf::Keyboard::Right) mY_Player.movePlayer('r', 10); // move Player 10 pixels right


				
			}
		}


		
		
		window.clear(sf::Color::Green);

		
		mY_Player.drawPlayer(window);  // to draw the sprite.....drawPlayer() is the function in player.h
		
		ui.draw(window);

		Player2.drawTo(window);		
	
		window.display();

	}

	return 0;
}