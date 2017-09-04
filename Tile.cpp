#include "Tile.h"

Tile::Tile() : image()
{
	;
}

Tile::Tile(const sf::Texture & texture) : image(texture)
{
	;
}

Tile::Tile(const sf::Texture & texture, const sf::IntRect & rectangle) : image(texture, rectangle)
{
	;
}

void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(image);
}

void Tile::setTexture(const sf::Texture & texture, bool resetRect)
{
	image.setTexture(texture, resetRect);
}

void Tile::setTextureRect(const sf::IntRect & rectangle)
{
	image.setTextureRect(rectangle);
}

void Tile::setPosition(const sf::Vector2f & position)
{
	image.setPosition(position);
}

void Tile::setType(const sf::String & type)
{
	this->type = type;
}

sf::String Tile::getType() const
{
	return type;
}
