#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Stone.h"
#include "../include/ball.h"
#include "../include/particleSystem.h"

using namespace std;

stone Stone;
Ball ball;

bool loadTextures(sf::Texture& tex, string sFileName)
{
	bool bSuccess;
	bSuccess = tex.loadFromFile(".\\assets\\textures\\" + sFileName);
	if (!bSuccess)
	{
		return false;
	}
	return true;
}


int main()
{
	// Create a window with the constructor
	sf::RenderWindow window(sf::VideoMode(800, 600), "vertex and particles");

	window.setPosition(sf::Vector2i(100, 100)); // Set the position of the window to 100,100
	window.setFramerateLimit(60); // Set the limit of the the number of frames per second

	sf::Vertex vertex(sf::Vector2f(10.f, 50.f), sf::Color::Red, sf::Vector2f(100.f, 100.f));
	sf::VertexArray cube(sf::LineStrip, 11);
	cube[0].position = sf::Vector2f(300, 300);
	cube[1].position = sf::Vector2f(300, 200);
	cube[2].position = sf::Vector2f(200, 187);
	cube[3].position = sf::Vector2f(300, 175);
	cube[4].position = sf::Vector2f(400, 187);
	cube[5].position = sf::Vector2f(300, 200);
	cube[6].position = sf::Vector2f(400, 187);
	cube[7].position = sf::Vector2f(400, 287);
	cube[8].position = sf::Vector2f(300, 300);
	cube[9].position = sf::Vector2f(200, 282);
	cube[10].position = sf::Vector2f(200, 187);
	sf::VertexArray triangle(sf::TriangleStrip, 1000);
	for (int i = 0; i < 1000; i++)
	{
		int iRed = (rand() % 255);
		int iBlue = (rand() % 255);
		int iGreen = (rand() % 255);
		float fX = (rand() % 800);
		float fy = (rand() % 600);
		triangle[i].position = sf::Vector2f(fX, fy);
		triangle[i].color = sf::Color(iRed, iBlue, iGreen, 255);
	}
	ParticleSystem particles(1000000);
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
		}
		//sf::Vector2i mouse = sf::Mouse::getPosition(window);
		//particles.setEmitter(sf::Vector2f(250f,250f));

		window.clear();
		window.draw(cube);
		//window.draw(particles);
		window.display();
	}
}