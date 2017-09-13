#include "Projectile.h"

Projectile::Projectile()
{
	;
}

Projectile::Projectile(const sf::Vector2f & initialPosition, float power, float speed,
	unsigned projectileOwner)
{	
	this->projectileOwner = projectileOwner;
	this->speed = speed;
	this->power = power;

	create(initialPosition);
}

void Projectile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
}

void Projectile::updateMoving()
{
	body.move(sf::Vector2f(speed, 0));
}

unsigned Projectile::getOwner() const
{
	return projectileOwner;
}

sf::FloatRect Projectile::getGlobalBounds() const
{
	return body.getGlobalBounds();
}

float Projectile::getPower() const
{
	if (speed >= 0)
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

	switch (projectileOwner)
	{
	case 0:
		body.setFillColor(Color::Blue);
		break;
	case 1:
		body.setFillColor(Color::Green);
		break;
	default:
		body.setFillColor(sf::Color::White);
		break;
	}	
}
