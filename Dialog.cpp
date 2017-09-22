#include "Dialog.h"

Dialog::Dialog(const Team & winningTeam)
{
	createShape();
	createTexts(winningTeam);
}

void Dialog::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(frame);

	for (auto & text : texts)
	{
		target.draw(text);
	}
}

void Dialog::createShape()
{
	frame.setSize(sf::Vector2f(500, 300));
	frame.setOrigin(frame.getSize() / 2.0f);
	frame.setFillColor(Color::Grey);
	frame.setPosition(Config::windowSize.x / 2.0f, Config::windowSize.y / 2.0f);
	frame.setOutlineThickness(1);
	frame.setOutlineColor(Color::Blue);
}

void Dialog::createTexts(const Team & winningTeam)
{
	switch (winningTeam)
	{
	case Team::FIRST:
		texts[0].setString("FIRST TEAM WIN");
		break;
	case Team::SECOND:
		texts[0].setString("SECOND TEAM WIN");
		break;
	default:
		break;
	}	
	
	texts[0].setFillColor(Color::Orange);
	texts[0].setCharacterSize(45);
	texts[0].setFont(Data::font);
	texts[0].setOrigin(texts[0].getGlobalBounds().width / 2, texts[0].getGlobalBounds().height / 2);
	texts[0].setPosition(sf::Vector2f(frame.getGlobalBounds().left + frame.getGlobalBounds().width / 2,
		frame.getGlobalBounds().top + 60));

	texts[1].setString("\"Spacebar\" - play again");
	texts[2].setString("\"Escape\" - back to menu");

	for (int i = 1; i < 3; i++)
	{
		texts[i].setFont(Data::font);		
		texts[i].setFillColor(Color::Blue);
		texts[i].setCharacterSize(25);
		texts[i].setOrigin(texts[i].getGlobalBounds().width / 2, texts[i].getGlobalBounds().height / 2);
		texts[i].setPosition(sf::Vector2f(frame.getGlobalBounds().left + frame.getGlobalBounds().width / 2, 
			frame.getGlobalBounds().top + 70 * i + 80));
	}
}