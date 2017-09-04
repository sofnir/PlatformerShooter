#include "Map.h"

Map::Map()
	: mapSize(0, 0)
{
	;
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < tileMap.size(); i++)
	{
		for (int j = 0; j < tileMap[i].size(); j++)
		{
			target.draw(tileMap[i][j]);
		}
	}			
}

bool Map::load(const std::string & path)
{
	std::fstream file(path, std::ios::in);

	if (!file.is_open())
	{
		std::cout << "Map with this name propably doesn't exist\n";
		return false;
	}

	sf::Vector2i mapSize;
	file >> mapSize.x >> mapSize.y;

	if (mapSize.x < 1 || mapSize.y < 1)
	{
		std::cout << "Wrong map size\n";
		return false;
	}

	this->mapSize = mapSize;

	valueMap.clear();
	valueMap.resize(mapSize.y);

	for (int i = 0; i < mapSize.y; i++)
	{
		valueMap[i].resize(mapSize.x);
	}		

	std::string value;
	std::string xValue;
	std::string yValue;



	for (int i = 0; i < mapSize.y; i++)
	{
		for (int j = 0; j < mapSize.x; j++)
		{
			file >> value;

			int k = 0;
			xValue.clear();
			yValue.clear();

			while (value[k] != ',')
			{
				xValue += value[k];
				k++;
			}

			k++;

			while (value[k] != NULL)
			{
				yValue += value[k];
				k++;
			}
			
			valueMap[i][j] = sf::Vector2u(atoi(xValue.c_str()), atoi(yValue.c_str()));
		}
	}
}

void Map::showValues() const
{	
	std::cout << "Map size: " << mapSize.x << "x" << mapSize.y << std::endl;
	
	for (int i = 0; i < valueMap.size(); i++)
	{
		for (int j = 0; j < valueMap[i].size(); j++)
		{
			std::cout << valueMap[i][j].x << "," << valueMap[i][j].x << " ";
		}

		std::cout << std::endl;
	}
}

void Map::createTiles(const sf::Texture & tileSet, unsigned tileSize)
{
	tileMap.clear();
	tileMap.resize(mapSize.y);

	for (int i = 0; i < mapSize.y; i++)
	{
		tileMap[i].resize(mapSize.x);
	}

	for (int i = 0; i < tileMap.size(); i++)
	{
		for (int j = 0; j < tileMap[i].size(); j++)
		{
			tileMap[i][j] = Tile(tileSet, sf::IntRect(valueMap[i][j].x * tileSize, valueMap[i][j].y * tileSize, tileSize, tileSize));			
			tileMap[i][j].setPosition(sf::Vector2f(tileSize * j, tileSize * i));
		}
	}	
}