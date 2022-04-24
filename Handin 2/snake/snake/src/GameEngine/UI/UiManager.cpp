#include "..\..\..\include\GameEngine\UI\UiManager.h"

#include "..\..\..\include\GameEngine\UI\StartScreen.h"
#include "..\..\..\include\GameEngine\UI\GameLost.h"
#include "..\..\..\include\GameEngine\UI\GameWon.h"

UIStartScreen startScreen;
UIGameLost gameLost;
UIGameWon gameWon;

bool Menu::loadAllImages()
{
	if (startScreen.loadImage() == false) { return false; };
	if (gameLost.loadImage() == false) { return false; };
	if (gameWon.loadImage() == false) { return false; };
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
		gameWon.draw(window);
	}
	else if (iMenuType == 2)
	{
		gameLost.draw(window);
	}
	
}
void Menu::setText(int iMenuType, int iInput)
{
	//0=start
	//1=game won
	//2=game lost
	if (iMenuType == 0)
	{
		startScreen.setDiff(iInput);
	}
	else if (iMenuType == 1)
	{
	}
	else if (iMenuType == 2)
	{
		gameLost.setText(iInput);
	}
}
