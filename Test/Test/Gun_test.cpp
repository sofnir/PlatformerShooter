#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <vector>
#include "../Gun.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Gun - test");
	window.setFramerateLimit(60);

	std::vector<Projectile> projectiles;	

	Gun gun(30.0f, 8.0f, 0.3f);
	gun.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	std::cout << "Space - shoot\n\n";
	std::cout << "Reload time: " << gun.getReloadTime() << std::endl;
	std::cout << "Power: " << gun.getPower() << std::endl;
	std::cout << "Speed: " << gun.getSpeed() << std::endl;

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
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				if (gun.isReady())
				{
					projectiles.push_back(gun.createProjectile(0));
				}				
			}
		}

		window.clear();
		for (auto & projectile : projectiles)
		{
			window.draw(projectile);
		}
		window.draw(gun);
		window.display();
	}

	return 0;
}