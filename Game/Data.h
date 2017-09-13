#pragma once
#include <SFML\Graphics\Font.hpp>

class Data
{
public:
	Data();

	static sf::Font font;	
};

namespace Color
{	
	const sf::Color Blue(69, 159, 212);
	const sf::Color Green(44, 191, 164);
	const sf::Color Grey(22, 27, 32);
	const sf::Color White(210, 211, 214);
}

namespace Config
{
	const sf::Vector2u windowSize(800, 600);
}
