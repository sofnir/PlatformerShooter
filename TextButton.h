#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class TextButton : public sf::Drawable
{
public:
	TextButton();
	TextButton(const sf::String & string, const sf::Font & font, unsigned int characterSize = 30);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	void update(const sf::Vector2f & mousePosition);
	bool isHover(const sf::Vector2f & mousePosition) const;

	void setString(const sf::String & string);
	void setFont(const sf::Font & font);
	void setCharacterSize(unsigned int size);
	void setFillColor(const sf::Color & color);
	void setHoverColor(const sf::Color & color);
	void setResizing(bool resize);
	void setOrigin(const sf::Vector2f & origin);
	void setPosition(const sf::Vector2f & position);

private:
	sf::Text text;
	bool resizing;
	unsigned int basicCharacterSize;
	sf::Color basicColor;
	sf::Color newColor;
};