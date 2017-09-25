#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>
#include <memory>
#include <vector>
#include "Data.h"
#include "Animation.h"
#include "KeyboardController.h"
#include "Projectile.h"

class Character : public sf::Drawable
{
public:	
	struct RespawnParameters
	{
		sf::Vector2f position;
		bool face;
	};

	Character(const Team & team, CharecterController * controller, const RespawnParameters & respawn);		

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
	void updateController(sf::Event & event);
	void update(float dt);
	sf::RectangleShape & getBody();
	const sf::Vector2f & getVelocity() const;
	void setOnTheGround(bool state);
	void stopFalling();
	void shoot(std::vector<Projectile> & projectiles);
	const Team & getTeam() const;
	void initialForce(float force);
	int getLifes() const;
	void reset(const sf::Vector2f & position, bool face);

private:
	Team team;
	GunParameters superGun{ 0.8f, 20.0f, 10.0f };

	sf::Vector2f velocity = sf::Vector2f(0, 0);
	float speed = 5.0f;	
	float gravity = 0.4f;
	float jumpPower = 100.0f;
	int jumpsCount = 0; //how many times player can jump
	float kickVelocity = 0.0f;
	float kickReductor = 0.4f;	
	float reloadTimer = 0.0f;
	bool faceRight;
	bool onTheGround = false;
	unsigned startingLifes = 3;
	unsigned currentLifes;
	RespawnParameters respawnParameters;
	
	std::unique_ptr<CharecterController> characterController;
	sf::RectangleShape body;
	Animation animation;

	void createBody();
	void updateAnimations();
	void updateMove();
	void updateJump();
	void updateMoveDown();
	void updateKick();
	void updateDead();
};
