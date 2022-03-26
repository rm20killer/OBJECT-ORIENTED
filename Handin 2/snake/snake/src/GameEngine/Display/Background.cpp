#include "../../../include/GameEngine/Display/Background.h"



/// <summary>
/// load texture from file and set it to a sprite while giving textures
/// </summary>
/// <returns>
/// false if loading failed
/// true if loaded
/// </returns>
bool Background::loadImage()
{
	//load and set texture
	if (!texture.loadFromFile("..\.\\..\\assets\\texures\\stone.png")) return false;
	texture.setRepeated(true);
	sprite.setTexture(texture);
	//set scale
	sprite.setTextureRect(sf::IntRect(0,0, 600, 600));
	sprite.setPosition(0, 0);
	return true;
	
}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

