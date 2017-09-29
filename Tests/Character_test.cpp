#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <vector>
#include "../Character.h"
#include "../Collision.h"
#include "../Map.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Character - test");
	window.setFramerateLimit(60);

	Data data;
	sf::Clock clock;
	Collision collision;
	Map map;

	std::vector<Projectile> projectiles;
	std::vector<Character> players;

	players.push_back(Character(Team::FIRST, new KeyboardController(KeyboardController::Keys::ARROWS), {sf::Vector2f(100, 300), true}));
	
	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();

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

			for (auto & player : players)
			{
				player.updateController(event);
			}
		}

		//collision
		collision.playersWithPlatforms(players, map.getPlatforms());
		collision.playersWithProjectiles(players, projectiles);

		//update
		for (auto & player : players)
		{			
			player.update(dt);
			player.shoot(projectiles);			
		}		

		for (auto & projectile : projectiles)
		{
			projectile.updateMoving();
		}

		//drawing
		window.clear(Color::Grey);
		window.draw(map);
		
		for (auto & projectile : projectiles)
		{
			window.draw(projectile);
		}

		for (auto & player : players)
		{
			window.draw(player);
		}				

		window.display();
	}

	return 0;
}