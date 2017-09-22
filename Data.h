#pragma once
#include <SFML\Graphics\Font.hpp>

class Data
{
public:
	Data();

	static sf::Font font;	
	static sf::Texture playerTexture;
};

namespace Color
{	
	const sf::Color Blue(69, 159, 212);
	const sf::Color Green(44, 191, 164);
	const sf::Color Grey(22, 27, 32);
	const sf::Color Orange(190, 76, 45);
	const sf::Color White(210, 211, 214);
}

namespace Config
{
	const sf::Vector2u windowSize(800, 600);
}

struct GunParameters
{
	float reloadTime;
	float missilePower;
	float missileSpeed;
};

enum class Team
{
	FIRST,
	SECOND
};