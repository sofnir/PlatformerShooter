#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include "../Character.h"
#include "../Map.h"
#include "../ProjectilesManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Player - test");
	window.setFramerateLimit(60);		

	std::vector<Character> players;
	players.push_back(Character(0));
	players.push_back(Character(1));
	players[0].setPosition(sf::Vector2f(500.0f, 100.0f));		
	players[1].setPosition(sf::Vector2f(200.0f, 100.0f));	

	Map map;
	ProjectilesManager projectileManager;

	while (window.isOpen())
	{					
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
		}	

		projectileManager.updateMoving();		
		projectileManager.updateCollision(players);

		for (auto & player : players)
		{
			player.updateController(event);
			player.updateMoving();
			player.updateCollision(map.getPlatforms());
			
			if (player.isShooting())
			{
				projectileManager.addProjectile(player.getGun().createProjectile(player.getPlayer()));
			}
		}

		window.clear();
		window.draw(map);		
		for (auto & player : players)
		{
			window.draw(player);
		}
		projectileManager.draw(window);
		window.display();
	}

	return 0;
}