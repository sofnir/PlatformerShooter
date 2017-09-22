#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Data.h"

class CharacterGUI : public sf::Drawable
{
public:
	CharacterGUI(const std::string & characterName);
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	void setHp(int value);
	void setPosition(const sf::Vector2f & position);

private:
	sf::Text hp;
	std::string name;
};
