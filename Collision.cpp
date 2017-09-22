#include "Collision.h"

Collision::Collision()
{
	;
}

void Collision::playersWithPlatforms(std::vector<Character>& players, const std::vector<sf::RectangleShape>& platforms)
{
	for (auto & player : players)
	{		
		if (player.getVelocity().y > 0)
		{		
			sf::RectangleShape body = player.getBody();									

			sf::Vector2f playerPosition = body.getPosition();
			sf::Vector2f playerHalfSize = body.getSize() / 2.0f;

			player.setOnTheGround(false);

			for (auto & platform : platforms)
			{
				/* fix bug when jump and intersect with platform which is above and teleport on the platform when
				foots are still below the platform */
				if (body.getPosition().y + body.getSize().y / 2 > platform.getPosition().y && player.getVelocity().y < 6.0f)
				{
					continue;
				}

				sf::Vector2f platformPosition = platform.getPosition();
				sf::Vector2f platformHalfSize = platform.getSize() / 2.0f;

				//calculate distance between cener of objects
				float deltaX = platformPosition.x - playerPosition.x;
				float deltaY = platformPosition.y - playerPosition.y;

				//caluclate intersect of the objects
				float intersectX = abs(deltaX) - (platformHalfSize.x + playerHalfSize.x);
				float intersectY = abs(deltaY) - (platformHalfSize.y + playerHalfSize.y);

				//stop falling
				if (intersectX <= 0.0f && intersectY <= 0.0f && intersectX < intersectY && deltaY > 0.0f)
				{
					player.getBody().move(0, intersectY);
					player.stopFalling();
				}
			}			
		}
	}	
}

void Collision::playersWithProjectiles(std::vector<Character> & players, std::vector<Projectile> & projectiles)
{
	for (auto & player : players)
	{		
		std::vector<Projectile>::iterator ptr;
		for (ptr = projectiles.begin(); ptr != projectiles.end();)
		{			
			if (ptr->getOwner() != player.getTeam())
			{
				if (ptr->getGlobalBounds().intersects(player.getBody().getGlobalBounds()))
				{
					player.initialForce(ptr->getPower());
					ptr = projectiles.erase(ptr);
					continue;
				}
				else if (ptr->getGlobalBounds().left + ptr->getGlobalBounds().width > 800.0f || ptr->getGlobalBounds().left < 0.0f)
				{
					ptr = projectiles.erase(ptr);
					continue;
				}				
			}	
						
			ptr++;			
		}
	}	
}