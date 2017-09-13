#pragma once
#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include <vector>
#include "Data.h"

class Map : public sf::Drawable
{
public:
	Map();
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	std::vector<sf::RectangleShape> getPlatforms() const;

private:
	std::vector<sf::RectangleShape> platforms;
};