#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../Animation.h"
#include "../Data.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Map - test");
	window.setFramerateLimit(60);

	Data data;

	sf::RectangleShape body;
	body.setSize(sf::Vector2f(56.0f, 80.0f));
	body.setOrigin(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));
	body.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	body.setTexture(&Data::playerTexture);
	body.setTextureRect(sf::IntRect(0, 0, 56.0f, 80.0f));

	Animation animation(body.getSize(), sf::Vector2u(3, 9), 0.15f);

	int currentFrame = 0;	

	while (window.isOpen())
	{	
		animation.update(currentFrame, true);
		body.setTextureRect(animation.getuvRect());

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Escape: 
					window.close();
					break;
				case sf::Keyboard::Num1:
					currentFrame = 0;
					break;				
				case sf::Keyboard::Num2:
					currentFrame = 1;
					break;
				case sf::Keyboard::Num3:
					currentFrame = 8;
					break;
				default:
					break;
				}
			}
		}

		window.clear(sf::Color::White);
		window.draw(body);
		window.display();
	}
	return 0;
}