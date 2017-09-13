#include "ProjectilesManager.h"

ProjectilesManager::ProjectilesManager()
{
	;
}

void ProjectilesManager::updateMoving()
{
	for (auto & projectile : projectiles)
	{
		projectile.updateMoving();
	}
}

void ProjectilesManager::draw(sf::RenderWindow & window) const
{
	for (auto & projectile : projectiles)
	{
		window.draw(projectile);
	}
}

void ProjectilesManager::addProjectile(Projectile projectile)
{
	projectiles.push_back(projectile);
}

void ProjectilesManager::updateCollision(std::vector<Character> & players)
{
	for (auto & player : players)
	{
		std::vector<Projectile>::iterator ptr;
		for (ptr = projectiles.begin(); ptr != projectiles.end();)
		{		
			if (player.getGlobalBounds().intersects(ptr->getGlobalBounds())
				&& ptr->getOwner() != player.getPlayer())
			{
				player.initialForce(ptr->getPower());
				ptr = projectiles.erase(ptr);				
			}
			else if (ptr->getGlobalBounds().left < minExisingDistance ||
				ptr->getGlobalBounds().left > maxExistingDistance)
			{
				ptr = projectiles.erase(ptr);
			}
			else
			{
				ptr++;
			}
		}
	}
}
