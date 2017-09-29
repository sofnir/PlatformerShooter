#include "Data.h"

sf::Font Data::font;
sf::Texture Data::playerTexture;

Data::Data()
{
	font.loadFromFile("Data/font.ttf");	
	playerTexture.loadFromFile("Data/player.png");
}
