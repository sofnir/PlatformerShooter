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

	sf::Vector2f initialPoint = sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	GunParameters defaultGun{ 0.8f, 20.0f, 5.0f };
	GunParameters superGun{ 0.1f, 40.0f, 10.0f };

	sf::Clock clock;

	float defaultGunTimer = 0.0f;
	float superGunTimer = 0.0f;

	while (window.isOpen())
	{				
		float dt = clock.restart().asSeconds();
		
		defaultGunTimer += dt;
		superGunTimer += dt;

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
				if (defaultGunTimer > defaultGun.reloadTime)
				{
					projectiles.push_back(Projectile(initialPoint, Team::FIRST, defaultGun, true));
					defaultGunTimer = 0.0f;
				}				
			}
			else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return)
			{
				if (superGunTimer > superGun.reloadTime)
				{
					projectiles.push_back(Projectile(initialPoint, Team::SECOND, superGun, false));
					superGunTimer = 0.0f;
				}
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