#pragma once
#include "KeyboardController.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>
#include <memory>
#include <vector>
#include "Gun.h"

class ProjectileManager;

class Character : public sf::Drawable
{
public:		
	Character(unsigned player = 0);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void updateController(sf::Event & event);
	void updateMoving();
	void updateCollision(const std::vector<sf::RectangleShape> & platforms);
	void initialForce(float force);
	void setPosition(const sf::Vector2f & position);
	sf::FloatRect getGlobalBounds()	const;
	unsigned getPlayer() const;
	bool isShooting() const;	
	Gun & getGun();

private:
	unsigned player;
	sf::Vector2f velocity = sf::Vector2f(0, 0);
	float speed = 5.0f;
	float gravity = 0.4f;
	float jumpPower = 100.0f;		
	bool canJump = false;
	bool onTheGround = false;
	bool faceRight = true;
	
	std::unique_ptr<CharecterController> characterController;
	sf::RectangleShape body;
	Gun gun;

	void create();
	void move();
	void jump();
	void moveDown();
};
