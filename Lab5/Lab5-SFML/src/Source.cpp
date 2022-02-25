#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;

float iRectangleX = 0;
float iRectangleY = 0;

int fSizex = 1920;
int fSizey = 1080;

int iRed = 0;
int iBlue = 0;
int iGreen = 0;
int alpha = 255;
int main()
{
	//window maker
	sf::RenderWindow window(sf::VideoMode(fSizex, fSizey), "New window");
	window.setPosition(sf::Vector2i(100, 100));
	window.setFramerateLimit(0);
	
	//Timer
	sf::Clock Timer;
	int iCounter = 0;
	float lastTime = 0;

	//shape (rectangle)
	sf::RectangleShape myRectangle;
	myRectangle.setSize(sf::Vector2f(50.f, 50.0f));
	myRectangle.setOrigin(myRectangle.getSize().x/2.0f, myRectangle.getSize().y/2.0f);
	myRectangle.setPosition(iRectangleX, iRectangleY);
	myRectangle.setOutlineColor(sf::Color::Black);
	myRectangle.setFillColor(sf::Color::Red);
	myRectangle.setOutlineThickness(1.0f);


	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			/*
			if (event.type == sf::Event::KeyPressed)
			{
				int iRed = (rand() % 255);
				int iBlue = (rand() % 255);
				int iGreen =(rand() % 255);
				//sf::Color test(iRed, iBlue, iGreen , 0);
				myRectangle.setFillColor(sf::Color(iRed, iBlue, iGreen, 255));
				//up down
				if (event.key.code == sf::Keyboard::W) { 
					if (iRectangleY > 0) {
						window.draw(myRectangle);
						//window.display();
						iRectangleY = iRectangleY - 10;
						myRectangle.setPosition(iRectangleX, iRectangleY);
						//printf("%f and %f \n", iRectangleX, iRectangleY);
					}
					printf("The user pushed `W`\n");
				}
				if (event.key.code == sf::Keyboard::S) {
					if (iRectangleY < 600) {
						window.draw(myRectangle);
						//window.display();
						iRectangleY = iRectangleY + 10;
						myRectangle.setPosition(iRectangleX, iRectangleY);
						//printf("%f and %f \n", iRectangleX, iRectangleY);
					}
					printf("The user pushed `S`\n");
				}
				//left right
				if (event.key.code == sf::Keyboard::A) { 
					if (iRectangleX > 0) {
						window.draw(myRectangle);
						iRectangleX = iRectangleX - 10;
						myRectangle.setPosition(iRectangleX, iRectangleY);
						//printf("%f and %f \n", iRectangleX, iRectangleY);
					}
					printf("The user pushed `A`\n"); 
				}
				if (event.key.code == sf::Keyboard::D) {
					if (iRectangleY < 600) {
						window.draw(myRectangle);
						//window.display();
						iRectangleX = iRectangleX + 10;
						myRectangle.setPosition(iRectangleX, iRectangleY);
						//printf("%f and %f \n", iRectangleX, iRectangleY);
					}
					printf("The user pushed `D`\n");
				}
				if (event.key.code == sf::Keyboard::Space) { 
					printf("The User Pushed `Spacebar`\n"); 
				}
			}
			*/
		}
		//window.clear(sf::Color::White);
		while (iRectangleY < fSizey+500) {
			if (iRectangleX < fSizex+200) {
				int iRed = (rand() % 255);
				int iBlue = (rand() % 255);
				int iGreen = (rand() % 255);
				myRectangle.setFillColor(sf::Color(iRed, iBlue, iGreen, 255));
				window.draw(myRectangle);
				iRectangleX = iRectangleX + 10;
				myRectangle.setPosition(iRectangleX, iRectangleY);
				iCounter++;
				//printf("%i \n", iCounter);
			}
			else
			{
				iRectangleY = iRectangleY + 10;
				iRectangleX = 0;
			}
			window.display();
		}
		sf::Time elapsedTime = Timer.getElapsedTime();
		if (elapsedTime.asSeconds() > 1.0f)
		{
			//iCounter++;
			//if (iCounter == 100)
			//{
			//	iCounter = 0;
			//}
		}
		//system("pause");
		//return 0;
	}
}