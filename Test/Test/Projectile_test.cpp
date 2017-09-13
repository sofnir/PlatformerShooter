#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <vector>
#include "../Projectile.h"

int main()
{	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Projectile - test");
	window.setFramerateLimit(60);
	
	std::vector<Projectile> projectiles;
	std::cout << "Space - create default projectile\n";
	std::cout << "Enter - create super projectile\n";

	while (window.isOpen())
	{		
		std::vector<Projectile>::iterator ptr;
		for (ptr = projectiles.begin(); ptr != projectiles.end();)
		{
			ptr->updateMoving();

			if (ptr->getGlobalBounds().left + ptr->getGlobalBounds().width > window.getSize().x - 50.0f
				|| ptr->getGlobalBounds().left < 50.0f)								
			{				
				ptr = projectiles.erase(ptr);
			}
			else
			{
				ptr++;
			}			
		}

		sf::Event event;
		while (window.pollEvent(event))
		{			
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
			{
				projectiles.push_back(Projectile(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f)));
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			{
				projectiles.push_back(Projectile(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f), 40.0f, -10.0f, 1));
			}
		}

		window.clear();		
		for (auto & projectile : projectiles)
		{
			window.draw(projectile);
		}
		window.display();
	}

	return 0;
}