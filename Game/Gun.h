#pragma once
#include <SFML\Graphics\Drawable.hpp>
#include <SFML\Graphics\RenderTarget.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\System\Clock.hpp>
#include "Projectile.h"
#include "Data.h"

class Gun : public sf::Drawable
{
public:
	Gun(float power = 100.0f, float speed = 5.0f, float reloadTime = 0.5f);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	Projectile createProjectile(int player);
	void setPosition(const sf::Vector2f & position);
	void setFaceRight(bool state);
	bool isReady() const;
	float getReloadTime() const;
	float getPower() const;
	float getSpeed() const;
	sf::FloatRect getGlobalBounds()	const;

private:
	sf::RectangleShape body;
	sf::Clock reloadTimer;
	float reloadTime;
	float power;
	float speed;
	bool faceRight = true;

	void create();
};

