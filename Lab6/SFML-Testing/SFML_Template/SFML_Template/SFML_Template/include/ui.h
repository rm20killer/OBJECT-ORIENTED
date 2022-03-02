#pragma once

#include"SFML/Graphics.hpp"

class UI
{


public:
	UI();                                        // Setting the text parameters
	void draw(sf::RenderWindow &window);          // drawing the text on the window.
	void setTextString(const std::string& text);
	void onMouseMoved(const sf::Vector2i& pixelCoords);
private:
	sf::Font m_font;
	sf::Text m_text;



};