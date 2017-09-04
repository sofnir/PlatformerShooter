#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class Tile : public sf::Drawable
{
public:
	Tile();
	Tile(const sf::Texture & texture);
	Tile(const sf::Texture & texture, const sf::IntRect & rectangle);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

	void setTexture(const sf::Texture &texture, bool resetRect = false);
	void setTextureRect(const sf::IntRect & rectangle);
	void setPosition(const sf::Vector2f & position);
	void setType(const sf::String & type);	

	sf::String getType() const;

private:
	sf::Sprite image;
	sf::String type = "none";
};