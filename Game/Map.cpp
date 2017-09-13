#include "Map.h"

Map::Map()
{
	sf::RectangleShape platform(sf::Vector2f(200, 4));
	platform.setOrigin(100, 2);
	platform.setFillColor(Color::White);
	platform.setPosition(150, 400);
	platforms.push_back(platform);
	platform.setPosition(300, 270);
	platforms.push_back(platform);
	platform.setPosition(300, 300);
	platforms.push_back(platform);
	platform.setPosition(550, 400);
	platforms.push_back(platform);
	platform.setPosition(650, 200);
	platforms.push_back(platform);
	platform.setSize(sf::Vector2f(800, 4));
	platform.setOrigin(400, 2);
	platform.setFillColor(Color::White);
	platform.setPosition(400, 500);
	platforms.push_back(platform);
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto & platform : platforms)
	{
		target.draw(platform);
	}	
}

std::vector<sf::RectangleShape> Map::getPlatforms() const
{
	return platforms;
}

