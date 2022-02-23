#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
	// Create a window with the constructor
	sf::RenderWindow window(sf::VideoMode(800, 600), "My first SFML window");

	window.setPosition(sf::Vector2i(100, 100)); // Set the position of the window to 100,100

	window.setFramerateLimit(60); // Set the limit of the the number of frames per second

	bool bIsUpPressed = false;
	bool bIsLeftPressed = false;

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
				if (event.key.code == sf::Keyboard::W) cout << "The user pressed the W key." << endl;
				if (event.key.code == sf::Keyboard::A) cout << "The user pressed the A key." << endl;
				if (event.key.code == sf::Keyboard::S) cout << "The user pressed the S key." << endl;
				if (event.key.code == sf::Keyboard::D) cout << "The user pressed the D key." << endl;
				if (event.key.code == sf::Keyboard::Space) {
					cout << "The user pressed the spacebar." << endl;
					if (event.key.code == sf::Keyboard::Up) bIsUpPressed = true;
					if (event.key.code == sf::Keyboard::Left) bIsLeftPressed = true;
				}

				// Process any keyrelases
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::Up) bIsUpPressed = false;
					if (event.key.code == sf::Keyboard::Left) bIsLeftPressed = false;
				}
			}

			// Key depressed?
			if (bIsUpPressed)
			{
				if (bIsLeftPressed)
				{
					cout << "Up and Left are both pressed" << endl;
				}
				else
				{
					cout << "Up is pressed" << endl;
				}
			}
			else
			{
				if (bIsLeftPressed)
				{
					cout << "Left is pressed" << endl;
				}
			}

			// TIme elapsed?
			sf::Time elapsedTime = timer.getElapsedTime(); // How much time has elapsed since last iteration

			if (elapsedTime.asSeconds() > 1.0f) // Has one second passed?
			{
				cout << iCounter << endl; // print out the counter
				iCounter++; // Increment the counter
				if (iCounter == 100) iCounter = 0; // keep the counter in bounds



				timer.restart(); // Restart the timer
			}
		}
	}
}