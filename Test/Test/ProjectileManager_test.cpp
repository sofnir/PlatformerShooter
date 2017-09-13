#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <vector>
#include "../ProjectilesManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Projectile manager - test");
	window.setFramerateLimit(60);

	ProjectilesManager projectilesManager;
	std::cout << "Space - shoot\n";

	std::vector<Character> players;	
	players.push_back(Character(1));
	players[0].setPosition(sf::Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f));
	
	while (window.isOpen())
	{		
		projectilesManager.updateMoving();
		projectilesManager.updateCollision(players);

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
				projectilesManager.addProjectile(Projectile(sf::Vector2f(50.0f, window.getSize().y / 2.0f)));
			}
		}

		window.clear();
		projectilesManager.draw(window);
		for (auto & player : players)
		{
			window.draw(player);
		}
		window.display();
	}

	return 0;
}