#include "Gun.h"

Gun::Gun(float power, float speed, float reloadTime)
	: power(power), speed(speed), reloadTime(reloadTime)
{
	reloadTimer.restart();
	create();
}

void Gun::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
}

Projectile Gun::createProjectile(int player)
{
	reloadTimer.restart();
	if (faceRight)
	{
		return Projectile(sf::Vector2f(body.getPosition()), power, speed, player);
	}
	else
	{
		return Projectile(sf::Vector2f(body.getPosition()), power, -speed, player);
	}

}

void Gun::setPosition(const sf::Vector2f & position)
{
	body.setPosition(position);
}

void Gun::setFaceRight(bool state)
{
	faceRight = state;
}

bool Gun::isReady() const
{
	if (reloadTimer.getElapsedTime().asSeconds() > reloadTime)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Gun::getReloadTime() const
{
	return reloadTime;
}

float Gun::getPower() const
{
	return power;
}

float Gun::getSpeed() const
{
	return speed;
}

sf::FloatRect Gun::getGlobalBounds() const
{
	return body.getGlobalBounds();
}

void Gun::create()
{
	body.setSize(sf::Vector2f(10, 10));
	body.setOrigin(sf::Vector2f(body.getSize().x / 2.0f, body.getSize().y / 2.0f));
}
