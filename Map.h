#pragma once
#include "SFML\Graphics\Drawable.hpp"
#include <SFML\Graphics\RenderTarget.hpp>
#include "SFML\Graphics\Texture.hpp"
#include <fstream>
#include <iostream>
#include "Tile.h"

class Map : public sf::Drawable
{
public:
	Map();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	bool load(const std::string & path);

	void showValues() const;
	void createTiles(const sf::Texture & tileSet, unsigned tileSize);

private:
	sf::Vector2i mapSize;
	std::vector <std::vector <Tile> > tileMap;
	std::vector <std::vector <sf::Vector2u> > valueMap;
};
