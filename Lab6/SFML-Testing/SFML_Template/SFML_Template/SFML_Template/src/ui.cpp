#include"../include/ui.h"
#include<iostream>

using namespace std;

UI::UI()
{
	 const char* fontFile = "./assets/fonts/din1451alt.ttf";
	if (!m_font.loadFromFile(fontFile))
	{
		char ch;
		std::cout << "Could not load font from file: " << fontFile << std::endl;
		std::cin >> ch;
		exit(1);
	}

	m_text.setFont(m_font);
	m_text.setCharacterSize(40);
	m_text.setFillColor(sf::Color::Yellow);
	m_text.setPosition({ 100.f, 780.f });
}

void UI::draw(sf::RenderWindow &window) 
{
	
	window.draw(m_text);
}

void UI::setTextString(const std::string& text)
{
	m_text.setString(text);
}

void UI::onMouseMoved(const sf::Vector2i& pixelCoords)
{
}
