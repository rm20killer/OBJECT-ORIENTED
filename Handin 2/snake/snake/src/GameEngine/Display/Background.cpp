#include "../../../include/GameEngine/objects/Background.h"



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
	if (!texture.loadFromFile("..\..\\..\\assets\\texures\\grid50.png")) return false;
	texture.setRepeated(true);
	sprite.setTexture(texture);
	//set scale
	sprite.setTextureRect(sf::IntRect(0,0, 600, 600));
	sprite.setPosition(0, 0);
	return true;
	//11x11
}

void Background::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

