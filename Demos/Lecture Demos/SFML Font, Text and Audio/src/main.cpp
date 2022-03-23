#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;


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
	bool bSoundFX = true;
	bool bSpatialFx = false;
	bool bMusic = false;

	// Create a window with the constructor
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Drawing Window"); 

	sf::Clock timer;

	sf::Vector2f ballVelocity(160.f,100.f);

	unsigned int uiHitCount = 0;

	// Load fonts
	sf::Font digitalFont;
	if(!digitalFont.loadFromFile(".\\assets\\fonts\\DIGITALDREAMFATSKEW.TTF")) return 0;

	sf::Font germanFont;
	if(!germanFont.loadFromFile(".\\assets\\fonts\\din1451alt.TTF")) return 0;

	// Set label text
	sf::Text scoreLabel;
	scoreLabel.setFont(digitalFont);
	scoreLabel.setString("Hit count");
	scoreLabel.setCharacterSize(16);
	scoreLabel.setPosition(610,100);
	scoreLabel.setFillColor(sf::Color::White);

	// Set score text
	sf::Text scoreText;
	scoreText.setFont(digitalFont);
	scoreText.setString(to_string(uiHitCount));
	scoreText.setCharacterSize(16);
	scoreText.setPosition(735,100);
	scoreText.setFillColor(sf::Color::White);

	// Set label
	sf::Text label;
	label.setFont(germanFont);
	label.setString("computerliebe");
	label.setCharacterSize(42);
	label.setPosition(670,480);
	label.setRotation(270);
	label.setFillColor(sf::Color::White);


	// Load sounds
	sf::SoundBuffer blopBuffer;
	if(!bSpatialFx)
	{
		if(!blopBuffer.loadFromFile(".\\assets\\audio\\beep.flac")) return 0;
	}
	else
	{
		if(!blopBuffer.loadFromFile(".\\assets\\audio\\beepMono.ogg")) return 0;
	}

	sf::Sound blopSound;
	blopSound.setBuffer(blopBuffer);

	if(!bSpatialFx) 
	{
		blopSound.setRelativeToListener(true);
		blopSound.setMinDistance(500.f);
		blopSound.setAttenuation(0.000001f);
	}
	
	sf::Listener::setPosition(50.f, 0.f, 50.f);
	sf::Listener::setDirection(1.f, 0.f, 1.f);


	// tile.png is a 50x50 pixel image
	sf::Texture tileTex;
	if(!tileTex.loadFromFile(".\\assets\\textures\\tile.png")) return 0;
	tileTex.setRepeated(true);

	sf::Sprite ceiling;
	ceiling.setTexture(tileTex);
	ceiling.setTextureRect(sf::IntRect(0,0,600,50));
	ceiling.setPosition(0,0);
	sf::FloatRect ceilingBb = ceiling.getGlobalBounds();

	sf::Sprite floor;
	floor.setTexture(tileTex);
	floor.setTextureRect(sf::IntRect(0,0,600,50));
	floor.setPosition(0,550);
	sf::FloatRect floorBb = floor.getGlobalBounds();

	sf::Sprite leftWall;
	leftWall.setTexture(tileTex);
	leftWall.setTextureRect(sf::IntRect(0,0,50,500));
	leftWall.setPosition(0,50);
	sf::FloatRect leftBb = leftWall.getGlobalBounds();

	sf::Sprite rightWall;
	rightWall.setTexture(tileTex);
	rightWall.setTextureRect(sf::IntRect(0,0,50,500));
	rightWall.setPosition(550,50);
	sf::FloatRect rightBb = rightWall.getGlobalBounds();

	float beachBallRadius = 30.f;
	sf::Vector2f beachBallSize(beachBallRadius*2.f, beachBallRadius*2.f);
	sf::Texture beachBallTex;
	sf::Sprite beachBall;
	loadTexture(beachBallTex, beachBall, "beachball.png", beachBallSize);
	beachBall.setPosition(375, 150);
	sf::FloatRect ballBb = beachBall.getGlobalBounds();

	sf::RectangleShape rightPanel;
	rightPanel.setSize(sf::Vector2f(200.f,800.f));
	rightPanel.setPosition(600.f,0.f);
	rightPanel.setFillColor(sf::Color::Blue);


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

		// Move beachBall
		sf::Time elapsedTime = timer.getElapsedTime();
		if(elapsedTime.asSeconds() > 0.01) 
		{
			// Move the ball and update it's bounding box
			sf::Vector2f deltaPositon = ballVelocity * elapsedTime.asSeconds();
			beachBall.move(deltaPositon.x, deltaPositon.y);
			ballBb = beachBall.getGlobalBounds();

			// Check if ball has collided with the arena

			// Hit ceiling
			if(ballBb.intersects(ceilingBb))
			{
				// Move away from ceiling
				beachBall.setPosition(beachBall.getPosition().x,81);
				// Reverse Y velocity
				ballVelocity.y = -ballVelocity.y;
				// Update hit count
				uiHitCount++;
				scoreText.setString(to_string(uiHitCount));
				if(bSpatialFx) blopSound.setPosition(beachBall.getPosition().x, 0.f, beachBall.getPosition().y);
				else blopSound.setPitch(1.0f + (float)uiHitCount * 0.01f);
				// Play sound
				if(bSoundFX) blopSound.play();
			}
			// Hit floor
			if(ballBb.intersects(floorBb))
			{
				// Move away from floor
				beachBall.setPosition(beachBall.getPosition().x,519);
				// Reverse Y velocity
				ballVelocity.y = -ballVelocity.y;
				// Update hit count
				uiHitCount++;
				scoreText.setString(to_string(uiHitCount));
				if(bSpatialFx) blopSound.setPosition(beachBall.getPosition().x, 0.f, beachBall.getPosition().y);
				else blopSound.setPitch(1.0f + (float)uiHitCount * 0.01f);
				// Play sound
				if(bSoundFX) blopSound.play();
			}
			// Hit walls
			if(ballBb.intersects(leftBb))
			{
				// Move away from wall
				beachBall.setPosition(81,beachBall.getPosition().y);
				// Reverse x velocity
				ballVelocity.x = -ballVelocity.x;
				// Update hit count
				uiHitCount++;
				scoreText.setString(to_string(uiHitCount));
				if(bSpatialFx) blopSound.setPosition(beachBall.getPosition().x, 0.f, beachBall.getPosition().y);
				else blopSound.setPitch(1.0f + (float)uiHitCount * 0.01f);
				// Play sound
				if(bSoundFX) blopSound.play();
			}
			if(ballBb.intersects(rightBb))
			{
				// Move away from wall
				beachBall.setPosition(519,beachBall.getPosition().y);
				// Reverse x velocity
				ballVelocity.x = -ballVelocity.x;
				// Update hit count
				uiHitCount++;
				scoreText.setString(to_string(uiHitCount));
				if(bSpatialFx) blopSound.setPosition(beachBall.getPosition().x, 0.f, beachBall.getPosition().y);
				else blopSound.setPitch(1.0f + (float)uiHitCount * 0.01f);
				// Play sound
				if(bSoundFX) blopSound.play();
			}

			timer.restart();
		}


		// Clear the window
		window.clear(sf::Color::White);

		window.draw(ceiling);
		window.draw(floor);
		window.draw(leftWall);
		window.draw(rightWall);

		window.draw(beachBall);

		window.draw(rightPanel);

		window.draw(scoreLabel);
		window.draw(scoreText);

		window.draw(label);

		// Display what ever has been drawn to the screen
		window.display(); 
	}

	return 0;
}


