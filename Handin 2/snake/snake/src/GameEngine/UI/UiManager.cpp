#include "..\..\..\include\GameEngine\UI\UiManager.h"

#include "..\..\..\include\GameEngine\UI\StartScreen.h"

UIStartScreen startScreen;
bool Menu::loadAllImages()
{
	if (startScreen.loadImage() == false) { return false; };
	return true;
}

void Menu::draw(sf::RenderWindow& window, int iMenuType)
{
	//0=start
	//1=game won
	//2=game lost
	if (iMenuType == 0)
	{
		startScreen.draw(window);
	}
	else if (iMenuType == 1)
	{
	}
	else if (iMenuType == 2)
	{
	}
	
}

