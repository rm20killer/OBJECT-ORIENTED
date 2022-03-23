#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;

//Function to allow an ease of creating a textured sprite. Note the use of references.
bool loadTexture(sf::Texture& tex, sf::Sprite& sprite, string sFileName, sf::Vector2f& size)
{
	bool bSuccess;
	bSuccess = tex.loadFromFile(".\\assets\\textures\\" + sFileName);
	if(!bSuccess)
	{
		return false;
	}

	sprite.setScale(size.x / tex.getSize().x, size.y / tex.getSize().y); 
	sprite.setOrigin(size.x / 2.f / sprite.getScale().x, size.y / 2.f  / sprite.getScale().y);
	sprite.setTexture(tex);
	return true;
}

int main()
{
	// Create a window with the constructor
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Drawing Window"); 

	sf::Texture tileTex;
	if(!tileTex.loadFromFile(".\\assets\\textures\\tile.png")) return 0;
	tileTex.setRepeated(true);

	sf::Sprite floor;
	floor.setTexture(tileTex);
	floor.setTextureRect(sf::IntRect(0,0,800,100));
	floor.setPosition(0,500);
	
	float beachBallRadius = 30.f;
	sf::Vector2f beachBallSize(beachBallRadius*2.f, beachBallRadius*2.f);
	sf::Texture beachBallTex;
	sf::Sprite beachBall;
	loadTexture(beachBallTex, beachBall, "beachball.png", beachBallSize);
	beachBall.setPosition(375, 150);

	sf::Texture stone;
	if (!stone.loadFromFile(".\\assets\\textures\\stone.png")) return 0;
	
	sf::Vector2f block1Size(200, 50);
	sf::Sprite block1;
	block1.setScale(block1Size.x / stone.getSize().x, block1Size.y / stone.getSize().y);
	block1.setOrigin(block1Size.x / 2.f / block1.getScale().x, block1Size.y / 2.f / block1.getScale().y);
	block1.setPosition(300, 400);
	block1.setRotation(20.f);
	block1.setTexture(stone);

	sf::Vector2f block2Size(100, 100);
	sf::Sprite block2;
	block2.setScale(block2Size.x / stone.getSize().x, block2Size.y / stone.getSize().y);
	block2.setOrigin(block2Size.x / 2.f / block2.getScale().x, block2Size.y / 2.f / block1.getScale().y);
	block2.setPosition(100, 300);
	block2.setColor(sf::Color::Magenta);
	block2.setTexture(stone);

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


		// Clear the window
		window.clear(sf::Color(150,150,150));
		
		window.draw(floor);

		window.draw(block1);
		window.draw(block2);


		// Display what ever has been drawn to the screen
		window.display(); 
	}

	return 0;
}


