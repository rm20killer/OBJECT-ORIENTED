#include "../../../include/GameEngine/Input/InputManager.h"
#include "../../../include/GameEngine/objects/ObjectManager.h"

Object object;
/// <summary>
/// check what key is pressed and change the direction depending on the key pressed
/// </summary>
/// <param name="event"></param>
void InputManager::KeyPressed(sf::Event event)
{
	//if event.key.code is w,a,s or d
	if (event.key.code == sf::Keyboard::W||event.key.code==sf::Keyboard::Up)
	{
		printf("'w' was pressed\n");
		object.snakeChangeDir(0);
	}
	if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
	{
		printf("'a' was pressed\n");
		object.snakeChangeDir(1);
	}
	if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
	{
		printf("'s' was pressed\n");
		object.snakeChangeDir(2);
	}
	if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
	{
		printf("'d' was pressed\n");
		object.snakeChangeDir(3);
	}
	
}