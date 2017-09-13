#pragma once
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RectangleShape.hpp>

class Projectile : public sf::Drawable
{
public:	
	Projectile();
	Projectile(const sf::Vector2f & initialPosition, float power = 20.0f, float speed = 5.0f, 
		unsigned projectileOwner = 0);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;	
	void updateMoving();

	float getPower() const;
	unsigned getOwner() const;
	sf::FloatRect getGlobalBounds()	const;

private:
	sf::RectangleShape body;
	unsigned projectileOwner;
	float power;
	float speed;	 

	void create(const sf::Vector2f & position);
};
