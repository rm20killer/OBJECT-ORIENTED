#include "../../../include/GameEngine/Input/InputManager.h"
#include "../../../include/GameEngine/objects/DisplayManager.h"

Object object;
void InputManager::KeyPressed(sf::Event event)
{
	//if event.key.code is w,a,s or d
	if (event.key.code == sf::Keyboard::W)
	{
		printf("'w' was pressed\n");
		object.snakeChangeDir(0);
	}
	if (event.key.code == sf::Keyboard::A)
	{
		printf("'a' was pressed\n");
		object.snakeChangeDir(1);
	}
	if (event.key.code == sf::Keyboard::S)
	{
		printf("'s' was pressed\n");
		object.snakeChangeDir(2);
	}
	if (event.key.code == sf::Keyboard::D)
	{
		printf("'d' was pressed\n");
		object.snakeChangeDir(3);
	}
	
}
