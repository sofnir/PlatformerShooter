#pragma once
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include "Data.h"

class Dialog : public sf::Drawable
{
public:

	Dialog(const Team & winningTeam);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:

	sf::RectangleShape frame;	
	sf::Text texts[3];

	void createShape();
	void createTexts(const Team & winningTeam);
};