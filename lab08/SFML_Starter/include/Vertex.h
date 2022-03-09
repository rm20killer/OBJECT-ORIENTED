#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class vetex
{
public:

	void generateTringle();
private:
	sf::Vertex vertex;
	sf::VertexArray triangle(sf::Triangles, 3);
};