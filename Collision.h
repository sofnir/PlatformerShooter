#pragma once
#include <vector>
#include "Character.h"
#include "Projectile.h"

class Collision
{
public:
	Collision();

	void playersWithPlatforms(std::vector<Character > & players, const std::vector<sf::RectangleShape > & platforms);
	void playersWithProjectiles(std::vector<Character > & players, std::vector<Projectile> & projectiles);
};