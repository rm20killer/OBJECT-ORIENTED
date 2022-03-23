#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;


int main()
{
	// Create a window with the constructor
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Drawing Window"); 

	window.setFramerateLimit(60); // Set the limit of the the number of frames per second

	sf::Clock timer;



	bool bUp = true;

	sf::CircleShape myCircle;
	myCircle.setRadius(15.0f);
	myCircle.setOrigin(15.0f, 15.0f);
	myCircle.setPosition(50.f,30.f);
	myCircle.setPointCount(50);
	myCircle.setFillColor(sf::Color::Magenta);

	sf::RectangleShape myRectA;
	myRectA.setSize(sf::Vector2f(60.f, 20.0f));
	myRectA.setPosition(70,150);
	myRectA.setOrigin(myRectA.getSize().x / 2.0f, myRectA.getSize().y / 2.0f);
	myRectA.setFillColor(sf::Color::Red);

	sf::RectangleShape myRectB;
	myRectB.setSize(sf::Vector2f(150.f, 175.0f));
	myRectB.setPosition(400,350);
	myRectB.setOrigin(myRectB.getSize().x / 2.0f, myRectB.getSize().y / 2.0f);
	myRectB.setFillColor(sf::Color::Blue);

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

		// Move circle
		sf::Time elapsedTime = timer.getElapsedTime();
		if(elapsedTime.asSeconds() > 0.05) 
		{
			if(bUp)
			{
				myCircle.move(0.0f,-5.0f);
				if(myCircle.getPosition().y < 0) bUp = false;
			}
			else
			{
				myCircle.move(0.0f,5.0f);
				if(myCircle.getPosition().y > 600) bUp = true;
			}
			timer.restart();
		}

		// Clear the window

		window.clear(sf::Color::White);

		sf::View mainView;
		mainView.setSize(400.f,300.f);
		mainView.setCenter(200.f,150.f);
		window.setView(mainView);

		window.draw(myRectA);
		window.draw(myRectB);
		window.draw(myCircle);

		sf::View miniWindow;
		miniWindow.setSize(800.f,600.f);
		miniWindow.setCenter(400.f,300.f);
		miniWindow.setViewport(sf::FloatRect(0.8f,0.0f,0.2f,0.2f));
		window.setView(miniWindow);

		sf::RectangleShape bg(sf::Vector2f(800.f,600.f));
		bg.setFillColor(sf::Color(200.f,200.f,200.f));
		window.draw(bg);
		window.draw(myRectA);
		window.draw(myRectB);
		window.draw(myCircle);

		// Display what ever has been drawn to the screen
		window.display(); 
    }

	return 0;
}


/*
int main()
{
	// Create a window with the constructor
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Drawing Window"); 

	window.setFramerateLimit(60); // Set the limit of the the number of frames per second

	sf::Clock timer;

	bool bUp = true;

	sf::RectangleShape myRectA;
	myRectA.setSize(sf::Vector2f(200.f, 120.0f));
	myRectA.setPosition(200,250);
	myRectA.setOrigin(myRectA.getSize().x / 2.0f, myRectA.getSize().y / 2.0f);
	myRectA.setFillColor(sf::Color::Red);

	sf::RectangleShape myRectB;
	myRectB.setSize(sf::Vector2f(150.f, 175.0f));
	myRectB.setPosition(400,350);
	myRectB.setOrigin(myRectB.getSize().x / 2.0f, myRectB.getSize().y / 2.0f);
	myRectB.setFillColor(sf::Color::Blue);

	sf::CircleShape myCircle;
	myCircle.setRadius(60.0f);
	myCircle.setOrigin(60.0f, 60.0f);
	myCircle.setPosition(650.f,300.f);
	myCircle.setPointCount(50);
	myCircle.setFillColor(sf::Color::Magenta);

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

			// Process key presses
			if(event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Up) myRectB.move(0.f, -10.f); // move RectB 10 pixels up
				if(event.key.code == sf::Keyboard::Down) myRectB.move(0.f, 10.f); // move RectB 10 pixels down
				if(event.key.code == sf::Keyboard::Left) myRectB.move(-10.f, 0.f); // move RectB 10 pixels left
				if(event.key.code == sf::Keyboard::Right) myRectB.move(10.f, 0.f); // move RectB 10 pixels right
				if(event.key.code == sf::Keyboard::Tab && !event.key.shift) myRectB.rotate(5.0f); // Rotate RectB 5 degrees clockwise
				if(event.key.code == sf::Keyboard::Tab && event.key.shift) myRectB.rotate(-5.0f); // Rotate RectB 5 degrees counter clockwise
			}

			// Process mouse clicks
			if(event.type == sf::Event::MouseButtonPressed)
			{
				// user has done a left click
				if(event.mouseButton.button == sf::Mouse::Left)
				{
					sf::FloatRect rectABoundingBox = myRectA.getGlobalBounds();
					sf::Vector2f clickLocation(event.mouseButton.x, event.mouseButton.y);

					if(rectABoundingBox.contains(clickLocation))
					{
						if(myRectA.getFillColor() == sf::Color::Red)
						{
							myRectA.setFillColor(sf::Color::Green);
						}
						else
						{
							myRectA.setFillColor(sf::Color::Red);
						}
					}
				}
			}

        } 

		// Move circle
		sf::Time elapsedTime = timer.getElapsedTime();
		if(elapsedTime.asSeconds() > 0.05) // A 20th of a second has passed
		{
			if(bUp)
			{
				myCircle.move(0.0f,-5.0f);
				if(myCircle.getPosition().y < 0) bUp = false;
			}
			else
			{
				myCircle.move(0.0f,5.0f);
				if(myCircle.getPosition().y > 600) bUp = true;
			}
		}

		// Check for collisions
		sf::FloatRect rectABoundingBox = myRectA.getGlobalBounds();
		sf::Vector2f location(15.f,400.f);
		bool isIn = rectABoundingBox.contains(location);

		sf::FloatRect rectBBoundingBox = myRectB.getGlobalBounds();

		if(rectABoundingBox.intersects(rectBBoundingBox))
		{
			cout << "A and B bound boxes intersect." << endl;
		}
		else
		{
			cout << "A and B bound boxes do not intersect." << endl;
		}

		// Clear the window
		window.clear(sf::Color::White);

		window.draw(myRectA);
		window.draw(myRectB);
		window.draw(myCircle);

		// Display what ever has been drawn to the screen
		window.display(); 
    }

	return 0;
}
*/

/*


	sf::RectangleShape myRectangle;
	myRectangle.setSize(sf::Vector2f(200.f, 120.0f));
	myRectangle.setOrigin(myRectangle.getSize().x / 2.0f, myRectangle.getSize().y / 2.0f);
	myRectangle.setPosition(200,250);
	myRectangle.setFillColor(sf::Color::Red);
	myRectangle.setOutlineColor(sf::Color::Green);
	myRectangle.setOutlineThickness(10.f);

	sf::CircleShape myCircle;
	myCircle.setRadius(45.0f);
	myCircle.setOrigin(45.0f, 45.0f);
	myCircle.setPosition(300.f,310.f);
	myCircle.setPointCount(50);
	myCircle.setFillColor(sf::Color(170, 60, 160, 80));

	sf::CircleShape myTriangle;
	myTriangle.setPointCount(3);
	myTriangle.setFillColor(sf::Color::Red);
	myTriangle.setRadius(50.f);
	myTriangle.setOrigin(50.f,50.f);
	myTriangle.setPosition(100.f,300.f);

	sf::CircleShape mySquare;
	mySquare.setPointCount(4);
	mySquare.setFillColor(sf::Color(0,128,0));
	mySquare.setRadius(50.f);
	mySquare.setOrigin(50.f,50.f);
	mySquare.setPosition(225.f,300.f);

	sf::CircleShape myPentagon;
	myPentagon.setPointCount(5);
	myPentagon.setFillColor(sf::Color::Red);
	myPentagon.setRadius(50.f);
	myPentagon.setOrigin(50.f,50.f);
	myPentagon.setPosition(350.f,300.f);

	sf::CircleShape myHexagon;
	myHexagon.setPointCount(6);
	myHexagon.setFillColor(sf::Color(0,128,0));
	myHexagon.setRadius(50.f);
	myHexagon.setOrigin(50.f,50.f);
	myHexagon.setPosition(475.f,300.f);

	sf::CircleShape mySeptagon;
	mySeptagon.setPointCount(7);
	mySeptagon.setFillColor(sf::Color::Red);
	mySeptagon.setRadius(50.f);
	mySeptagon.setOrigin(50.f,50.f);
	mySeptagon.setPosition(600.f,300.f);

	sf::CircleShape myOctagon;
	myOctagon.setPointCount(8);
	myOctagon.setFillColor(sf::Color(0,128,0));
	myOctagon.setRadius(50.f);
	myOctagon.setOrigin(50.f,50.f);
	myOctagon.setPosition(725.f,300.f);


	sf::ConvexShape myConvexShape;
	myConvexShape.setPointCount(3);
	myConvexShape.setPoint(0, sf::Vector2f(180.f, 120.f));
	myConvexShape.setPoint(1, sf::Vector2f(400.f, 240.f));
	myConvexShape.setPoint(2, sf::Vector2f(60.f, 400.f));
	myConvexShape.setFillColor(sf::Color::Blue);

	sf::Vector2f sumOfPositions(0.f,0.f);
	sf::Vector2f centroid;
	for(int i = 0;i < myConvexShape.getPointCount();i++)
	{
		sumOfPositions += myConvexShape.getPoint(i);
	}
	centroid = sumOfPositions / (float)myConvexShape.getPointCount();

	myConvexShape.setOrigin(centroid);
	myConvexShape.setPosition(400.f,300.f);


		window.draw(myTriangle);
		window.draw(mySquare);
		window.draw(myPentagon);
		window.draw(myHexagon);
		window.draw(mySeptagon);
		window.draw(myOctagon);


		window.draw(myConvexShape);





			sf::RectangleShape Abb(sf::Vector2f(rectABoundingBox.width,rectABoundingBox.height));
	Abb.setPosition(rectABoundingBox.left, rectABoundingBox.top);
	Abb.setFillColor(sf::Color::Transparent);
	Abb.setOutlineColor(sf::Color::Black);
	Abb.setOutlineThickness(2.0f);

	sf::RectangleShape Bbb(sf::Vector2f(rectBBoundingBox.width,rectBBoundingBox.height));
	Bbb.setPosition(rectBBoundingBox.left, rectBBoundingBox.top);
	Bbb.setFillColor(sf::Color::Transparent);
	Bbb.setOutlineColor(sf::Color::Black);
	Bbb.setOutlineThickness(2.0f);


			window.draw(myRectA);
		window.draw(myRectB);

		window.draw(Abb);
		window.draw(Bbb);
	*/
