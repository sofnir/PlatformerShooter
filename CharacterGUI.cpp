#include "CharacterGUI.h"

CharacterGUI::CharacterGUI(const std::string & characterName)
{
	hp.setFont(Data::font);	
	hp.setCharacterSize(20);
	name = characterName;	
	hp.setString(name + " hp: ");
	hp.setOrigin(hp.getGlobalBounds().width / 2, 0);
}

void CharacterGUI::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(hp);
}

void CharacterGUI::setHp(int value)
{
	hp.setString(name + " hp: " + std::to_string(value));
	hp.setOrigin(hp.getGlobalBounds().width / 2, 0);
}

void CharacterGUI::setPosition(const sf::Vector2f & position)
{	
	hp.setPosition(position);
}
