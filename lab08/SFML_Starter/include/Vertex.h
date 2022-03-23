#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class vetex
{
public:

	void generateCube();
	void DrawCube(sf::RenderWindow& window);
private:
	sf::Vertex vertex;
	//sf::LinesStrip line;
	sf::VertexArray cube;
};