
#include "..\..\..\include\GameEngine\UI\StartScreen.h"

bool UIStartScreen::loadImage()
{
	if (!texture.loadFromFile("..\.\\..\\assets\\UI\\Start.png")) return false;
	sprite.setTexture(texture);

	sprite.setPosition(0, 0);
	if (!font.loadFromFile("..\.\\..\\assets\\Fonts\\Quinquefive-0Wonv.ttf"));
	text.setFont(font);
	text.setString("Difficulty : 1 (Very Easy)");
	//set text origin to center
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
	text.setPosition(600, 500);
	text.setCharacterSize(10);

	text2.setFont(font);
	text2.setString("arrow keys to change difficulty");
	//set text origin to center
	text2.setOrigin(text2.getGlobalBounds().width / 2, text2.getGlobalBounds().height / 2);
	text2.setPosition(700, 520);
	text2.setCharacterSize(10);
	return true;
}

void UIStartScreen::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(text);
	window.draw(text2);
}

void UIStartScreen::setDiff(int diff)
{	
	std::string diffIntext = "";
	if (diff == 1)
	{
		diffIntext = " (Very Easy)";
	}
	else if (diff == 2)
	{
		diffIntext = " (Easy)";
	}
	else if (diff == 3)
	{
		diffIntext = " (medium)";
	}
	else if (diff == 4)
	{
		diffIntext = " (Hard)";
	}
	else if (diff == 5)
	{
		diffIntext = " (Very Hard)";
	}
	else if (diff >= 21)
	{
		diffIntext = " (Your fault for picking this option)";
	}
	else if (diff >= 20)
	{
		diffIntext = " (I warned you)";
	}
	else if (diff >= 15)
	{
		diffIntext = " (why do you want to play like this?)";
	}
	else if (diff >= 10)
	{
		diffIntext = " (You should not do this)";
	}
	else if (diff >= 6)
	{
		diffIntext = " (Impossible)";
	}
	text.setString("Difficulty : "+ std::to_string(diff) + diffIntext);
}