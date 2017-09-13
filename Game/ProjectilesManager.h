#pragma once
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Projectile.h"
#include "Character.h"
#include "Data.h"

class ProjectilesManager
{
public:
	ProjectilesManager();

	void updateMoving();	
	void draw(sf::RenderWindow & window) const;
	void addProjectile(Projectile projectile);
	void updateCollision(std::vector<Character> & players);

private:
	std::vector<Projectile> projectiles;
	float maxExistingDistance = 1000.0f;
	float minExisingDistance = 0.0f;
};