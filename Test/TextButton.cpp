#include "TextButton.h"

TextButton::TextButton()
	: text(), basicColor(sf::Color::Black), newColor(sf::Color::Red), basicCharacterSize(30), resizing(true)
{
	;
}

TextButton::TextButton(const sf::String & string, const sf::Font & font, unsigned int characterSize)
	: text(string, font, characterSize), basicCharacterSize(characterSize), resizing(true),
	basicColor(sf::Color::White), newColor(sf::Color::Red)
{
	;
}

void TextButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(text);
}

void TextButton::update(const sf::Vector2f & mousePosition)
{
	if (text.getGlobalBounds().contains(mousePosition))
	{
		text.setFillColor(newColor);

		if (resizing)
		{
			text.setCharacterSize((unsigned)(basicCharacterSize * 1.2));			
			text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
		}
	}
	else
	{
		text.setFillColor(basicColor);

		if (resizing)
		{
			text.setCharacterSize(basicCharacterSize);
			text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
		}
	}
}

bool TextButton::isHover(const sf::Vector2f & mousePosition) const
{
	return (text.getGlobalBounds().contains(mousePosition));
}

void TextButton::setString(const sf::String & string)
{
	text.setString(string);
}

void TextButton::setFont(const sf::Font & font)
{
	text.setFont(font);
}

void TextButton::setCharacterSize(unsigned int size)
{
	text.setCharacterSize(size);
	basicCharacterSize = size;
}

void TextButton::setFillColor(const sf::Color & color)
{
	text.setFillColor(color);
	basicColor = color;
}

void TextButton::setHoverColor(const sf::Color & color)
{
	newColor = color;
}

void TextButton::setResizing(bool resize)
{
	resizing = resize;
}

void TextButton::setOrigin(const sf::Vector2f & origin)
{
	text.setOrigin(origin);
}

void TextButton::setPosition(const sf::Vector2f & position)
{
	text.setPosition(position);
}