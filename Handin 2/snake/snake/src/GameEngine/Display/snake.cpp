#include "../../../include/GameEngine/objects/snake.h"
#include "../../../include/GameEngine/Events/GameOver.h"
#include "../../../include/GameEngine/objects/SnakeBody.h"
#include "..\..\..\include\GameEngine\objects\food.h"
#include "..\..\..\include\GameEngine\Audio\AudioManger.h"
using namespace std;


food Food;
audioSanke audio;


/// <summary>
/// load texture from file and set it to a sprite while giving textures
/// </summary>
/// <returns>
/// false if loading failed
/// true if loaded
/// </returns>
bool SnakeHead::loadImage()
{
	foodEaten = 0;
	bool bFoodSet = false;
	NumberOfBody = 3;
	bIsLost = false;
	if (Food.loadImage() == false) { return false; };
	if (audio.LoadAllAudio() == false) { return false; };
	//sf::Vector2f scale(50, 50);
	sf::Vector2f IdleSize(50, 50);
	const sf::Vector2i sheetDims(4, 1);
	//load and set texture
	//if (!texture.loadFromFile("..\..\\..\\assets\\texures\\snakeHead.png")) return false;
	if(!texture.loadFromFile("..\..\\..\\assets\\texures\\snakeHead_spritesheet.png")) return false;
	sprite.setTexture(texture);
	for (int i = 0; i < sheetDims.x; i++)
	{
		for (int j = 0; j < sheetDims.y; j++)
		{
			Rects[i + j * 3] = sf::IntRect(i * IdleSize.x, j * IdleSize.y, IdleSize.x, IdleSize.y);
		}
	}
	sprite.setScale(IdleSize.x / texture.getSize().x * sheetDims.x, IdleSize.y / texture.getSize().y * sheetDims.y);
	sprite.setTexture(texture);
	sprite.setTextureRect(Rects[iNumFrames]);
	sprite.setOrigin(0, 0);
	//set scale
	//sprite.setScale(scale.x,scale.y);
	sprite.setPosition(300, 300);
	for (int i = 0; i < MaxNumberOfBody; i++)
	{
		/*
		if (i == MaxNumberOfBody-1)
		{
			snakebody[i].setTail();
		}
		else
		{
			snakebody[i].loadImage();
		}
		*/
		snakebody[i].loadImage();
	}
	while (bFoodSet==false)
	{
		sf::Vector2f foodPos = Food.generateRandomPosition();
		if (foodPos != sprite.getPosition())
		{
			Food.setPosition(foodPos);
			bFoodSet = true;
		}
	}
	return true;
}
/// <summary>
/// loops through the snake body and draws them
/// </summary>
/// <param name="window"></param>
void SnakeHead::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < NumberOfBody; i++)
	{
		snakebody[i].draw(window);
	}
	window.draw(sprite);
	Food.draw(window);
}

/// <summary>
/// move the snake by setting the new position of the head
/// and the position of the body to the previous body/head position
/// check if the snake is collided with it self or the wall if so `bIsLost = true`
/// check if the snake is collided with the food then add a body
/// </summary>
void SnakeHead::Move()
{
	for (int i = NumberOfBody; i >= 0; i=i-1)
	{
		if (i == 0)
		{
			snakebody[i].setPosition(sprite.getPosition());
		}
		else {
			snakebody[i].setPosition(snakebody[i - 1].ReturnPosition());
		}
		//snakebody[i].setRotation(Direction);
		sf::Vector2f Snakepos = snakebody[i].ReturnPosition();
		sf::Vector2f Snake2pos = snakebody[i+1].ReturnPosition();
		cout << "Snake pos: " << Snakepos.x << " " << Snakepos.y << endl;
		cout << "Snake2 pos: " << Snake2pos.x << " " << Snake2pos.y << endl;
		float snakeDirectionX = Snakepos.x - Snake2pos.x;
		float snakeDirectionY = Snakepos.y - Snake2pos.y;
		cout<< snakeDirectionX << " " << snakeDirectionY << endl;
		if(snakeDirectionX == -50)
		{
			snakebody[i].setRotation(1);
		}
		else if (snakeDirectionX == 50)
		{
			snakebody[i].setRotation(3);
		}
		else if (snakeDirectionY == -50)
		{
			snakebody[i].setRotation(0);
		}
		else if (snakeDirectionY == 50)
		{
			snakebody[i].setRotation(2);
		}
		else
		{
			snakebody[i].setRotation(Direction);
		}
		
		//snakebody[i].setRotation(Direction);
	}
	//0 up, 1 left, 2 down 3 right
	if (Direction == 0)
	{
		sprite.setTextureRect(Rects[0]);
		//rotate the head
		if (sprite.getPosition().y > 50)
		{
			sprite.move(0, -50);
		}
		else
		{
			bIsLost = true;
			//sprite.setPosition(300, 300);
		}
	}
	if (Direction == 1)
	{
		sprite.setTextureRect(Rects[1]);
		//rotate the head
		if (sprite.getPosition().x > 50)
		{
			sprite.move(-50, 0);
		}
		else 
		{
			bIsLost = true;			
			//sprite.setPosition(300, 300);
		}
	}
	if (Direction == 2)
	{
		sprite.setTextureRect(Rects[2]);
		//rotate the head
		if (sprite.getPosition().y < 550)
		{
			sprite.move(0, 50);
		}
		else
		{
			bIsLost = true;			
			//sprite.setPosition(300, 300);
		}
	}
	if (Direction == 3)
	{
		sprite.setTextureRect(Rects[3]);
		//rotate the head
		if (sprite.getPosition().x < 550)
		{
			sprite.move(50, 0);
		}
		else
		{
			bIsLost = true;
			//sprite.setPosition(300, 300);
		}
	}
	for (int i = 0; i < NumberOfBody; i++)
	{
		if (sprite.getPosition() == snakebody[i].ReturnPosition()) {
			bIsLost = true;
			//sprite.setPosition(300, 300);
		}
	}
	//if collided with food
	if (sprite.getPosition() == Food.ReturnPosition())
	{
		bool bFoodSet = false;
		if (foodEaten<FoodToWin)
		{
			foodEaten++;
			NumberOfBody++;
			printf ("%i\n", foodEaten);
		}
		while (bFoodSet == false)
		{
			printf("checking food position\n");
			int l = 0;
			sf::Vector2f foodPos = Food.generateRandomPosition();
			for (int i = 0; i < NumberOfBody; i++)
			{
				if (foodPos == snakebody[i].ReturnPosition()) {
					l++;
				}
			}
			if (foodPos != sprite.getPosition() && l==0)
			{
				Food.setPosition(foodPos);
				bFoodSet = true;
			}
		}
		audio.playAudio(1);
	}
}
/// <summary>
/// change the direction of the snake
/// prevent the user from changing direction opposite to the current direction
/// </summary>
/// <param name="dir"></param>
void SnakeHead::Turn(int dir)
{
	if (Direction == 0 && dir == 2) { return; };
	if (Direction == 2 && dir == 0) { return; };
	if (Direction == 1 && dir == 3) { return; };
	if (Direction == 3 && dir == 1) { return; };
	Direction = dir;
}
/// <summary>
/// return the position of the head
/// </summary>
/// <returns> Vector2f </returns>
sf::Vector2f SnakeHead::ReturnPosition()
{
	return sf::Vector2f(sprite.getPosition());
}

/// <summary>
/// check how many body parts the snake has and compare to check if the snake has eaten 5 food objects if so return 1 (win)
/// checks if the snake has lost if so return -1 (loss)
/// else return 0 (still playing)
/// </summary>
/// <returns> bool </returns>
int SnakeHead::IsWon()
{
	if (foodEaten >= FoodToWin) //5 points
	{
		//win
		audio.playAudio(4);
		return 1;
	}
	else {
		if(bIsLost == true){
			//lost
			audio.playAudio(5);
			return -1;
		}
		else {
			//still playing
			return 0;
		}
	}
}

int SnakeHead::ReturnFoodEaten()
{
	return foodEaten;
}