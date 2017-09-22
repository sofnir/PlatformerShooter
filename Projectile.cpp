#include "Projectile.h"

Projectile::Projectile(const sf::Vector2f & initialPosition, const Team & team, const GunParameters & parameters, bool rightDirection)
{
	this->team = team;
	speed = parameters.missileSpeed;
	power = parameters.missilePower;
	this->rightDirection = rightDirection;

	create(initialPosition);
}

void Projectile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
}

void Projectile::updateMoving()
{
	if (rightDirection)
	{
		body.move(sf::Vector2f(speed, 0));
	}
	else
	{
		body.move(sf::Vector2f(-speed, 0));
	}	
}

const Team & Projectile::getOwner() const
{
	return team;
}

sf::FloatRect Projectile::getGlobalBounds() const
{
	return body.getGlobalBounds();
}

float Projectile::getPower() const
{
	if (rightDirection)
	{
		return power;
	}
	else
	{
		return -power;
	}

}

void Projectile::create(const sf::Vector2f & position)
{
	body.setSize(sf::Vector2f(20, 4));
	body.setPosition(position);

	switch (team)
	{
	case Team::FIRST:
		body.setFillColor(Color::Blue);
		break;
	case Team::SECOND:
		body.setFillColor(Color::Green);
		break;
	default:
		body.setFillColor(sf::Color::White);
		break;
	}
}
