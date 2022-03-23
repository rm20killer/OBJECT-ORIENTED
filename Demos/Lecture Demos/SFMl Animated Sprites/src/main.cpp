#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;



int main()
{
	// Create a window with the constructor
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Drawing Window"); 

	sf::Clock timer;

	bool bSuccess;

	sf::Vector2f trafficLightSize(84,250);
	sf::Texture trafficLightTex;
	sf::Sprite trafficLightSprite;
	bSuccess = trafficLightTex.loadFromFile(".\\assets\\textures\\lights.png");
	// Check the texture has loaded
	if(!bSuccess)
	{
		// texture hasn't loaded do something!
		exit(1);
	}

	static const int iNumFrames = 4;
	int iCurrentFrame = 0;
	sf::IntRect trafficLightrects[iNumFrames];
	trafficLightrects[0] = sf::IntRect(0,0,84,249);
	trafficLightrects[1] = sf::IntRect(83,0,84,249);
	trafficLightrects[2] = sf::IntRect(166,0,84,249);
	trafficLightrects[3] = sf::IntRect(249,0,84,249);

	trafficLightSprite.setScale(trafficLightSize.x / trafficLightTex.getSize().x * 4.0f, trafficLightSize.y / trafficLightTex.getSize().y); 
	trafficLightSprite.setOrigin(trafficLightSize.x / 2.f / trafficLightSprite.getScale().x, trafficLightSize.y / 2.f  / trafficLightSprite.getScale().y);
	trafficLightSprite.setPosition(675,300);
	trafficLightSprite.setTexture(trafficLightTex);
	trafficLightSprite.setTextureRect(trafficLightrects[iCurrentFrame]);


	sf::Vector2f explosionSize(334, 320); // Number based on sheet dimension and tweaking
	sf::Texture explosionTex;
	sf::Sprite explosionSprite;

	bSuccess = explosionTex.loadFromFile(".\\assets\\textures\\explosion2.png"); // png file courtesy of the internet
	// Check the texture has loaded
	if (!bSuccess)
	{
		// texture hasn't loaded do something!
		exit(1);
	}

	bool bExplosionActive = false;

	int iCurrentFrame2 = 0;
	static const int iNumFrames2 = 24;
	const sf::Vector2i sheetDims(6, 4);
	sf::IntRect explosionRects[iNumFrames2];
	

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			explosionRects[i + j * 6] = sf::IntRect(i * explosionSize.x, j * explosionSize.y, explosionSize.x, explosionSize.y);
		}
	}
	
	explosionSprite.setScale(explosionSize.x / explosionTex.getSize().x * sheetDims.x, explosionSize.y / explosionTex.getSize().y * sheetDims.y);
	explosionSprite.setOrigin(explosionSize.x / 2.f / explosionSprite.getScale().x, explosionSize.y / 2.f / explosionSprite.getScale().y);
	explosionSprite.setTexture(explosionTex);
	explosionSprite.setTextureRect(explosionRects[iCurrentFrame2]);

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

			// Has use pressed space?
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				iCurrentFrame++;
				if(iCurrentFrame >= iNumFrames) iCurrentFrame = 0;
				trafficLightSprite.setTextureRect(trafficLightrects[iCurrentFrame]);
			}

			// Has the user clicked the left mouse button?
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
			{
				explosionSprite.setPosition(event.mouseButton.x, event.mouseButton.y);
				iCurrentFrame2 = 0;
				bExplosionActive = true;
			}
		}

		// Move frames on 
		sf::Time elapsedTime = timer.getElapsedTime();
		if(elapsedTime.asSeconds() > 1.0 / 120) 
		{
			if (bExplosionActive)
			{
				iCurrentFrame2++;
				if (iCurrentFrame2 > iNumFrames2)
				{
					iCurrentFrame2 = 0;
					bExplosionActive = false;
				}
				explosionSprite.setTextureRect(explosionRects[iCurrentFrame2]);
			}
			timer.restart();
		}

		// Clear the window
		window.clear(sf::Color::White);

		window.draw(trafficLightSprite);

		if (bExplosionActive)
		{
			window.draw(explosionSprite);
		}

		// Display what ever has been drawn to the screen
		window.display(); 
    }

	return 0;
}


