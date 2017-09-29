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

	sf::Texture texture;
	texture.loadFromFile("Data/player.png");
		
	sf::RectangleShape body;
	body.setSize(sf::Vector2f(32.0f, 32.0f));	
	body.setOrigin(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));
	body.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	body.setTexture(&texture);
	body.setTextureRect(sf::IntRect(0, 0, 32, 32));
	body.setScale(sf::Vector2f(3, 3));

	Animation animation(body.getSize(), 0.1f);
	animation.createAnimation("Iddle", 0, 5);
	animation.createAnimation("Run", 1, 10);
	animation.createAnimation("Jump", 2, 9);

	std::cout << "Press NUM1 - set basic animation\n";
	std::cout << "Press NUM2 - set iddle animation\n";
	std::cout << "Press NUM3 - set run animation\n";
	std::cout << "Press NUM3 - set jump animation\n";

	while (window.isOpen())
	{	
		animation.update(true);
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
					animation.setCurrentAnimation("Basic");
					break;				
				case sf::Keyboard::Num2:
					animation.setCurrentAnimation("Iddle");
					break;
				case sf::Keyboard::Num3:
					animation.setCurrentAnimation("Run");					
					break;
				case sf::Keyboard::Num4:
					animation.setCurrentAnimation("Jump");
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