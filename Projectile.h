#pragma once
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include "Data.h"

class Projectile : public sf::Drawable
{
public:	
	Projectile(const sf::Vector2f & initialPosition, const Team & team, const GunParameters & parameters, bool rightDirection);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void updateMoving();

	float getPower() const;
	const Team & getOwner() const;
	sf::FloatRect getGlobalBounds()	const;

private:
	sf::RectangleShape body;
	Team team;
	float power;
	float speed;
	bool rightDirection;

	void create(const sf::Vector2f & position);
};
