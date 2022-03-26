#include "../../../include/GameEngine/Input/InputManager.h"

void InputManager::KeyPressed(sf::Event event)
{
	//if event.key.code is w,a,s or d
	if (event.key.code == sf::Keyboard::W)
	{
		printf("'w' was pressed\n");
	}
	if (event.key.code == sf::Keyboard::A)
	{
		printf("'a' was pressed\n");
	}
	if (event.key.code == sf::Keyboard::S)
	{
		printf("'s' was pressed\n");
	}
	if (event.key.code == sf::Keyboard::D)
	{
		printf("'d' was pressed\n");
	}
	
}
