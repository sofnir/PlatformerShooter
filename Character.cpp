#include "Character.h"

Character::Character(const Team & team, CharecterController * controller, const RespawnParameters & respawn)
	: animation(sf::Vector2f(56.0f, 80.0f), sf::Vector2u(1, 1), 100.0f)
{	
	this->team = team;
	respawnParameters.position = respawn.position;
	faceRight = respawnParameters.face = respawn.face;	
	characterController = std::unique_ptr<CharecterController>(controller);
	createBody();
}

void Character::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);	
}

void Character::updateController(sf::Event & event)
{
	characterController->Control(event);
}

void Character::update(float dt)
{
	updateMove();
	updateJump();
	updateMoveDown();
	updateAnimations();
	updateKick();
	updateDead();

	reloadTimer += dt;
	velocity.y += gravity;		

	body.move(velocity);
}

void Character::createBody()
{
	body.setSize(sf::Vector2f(56.0f, 80.0f));
	body.setOrigin(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));
	body.setTexture(& Data::playerTexture);	
	body.setTextureRect(sf::IntRect(0, 0, 56, 80));
	body.setPosition(respawnParameters.position);
	
	switch (team)
	{
	case Team::FIRST:
		body.setFillColor(Color::Blue);
		break;
	case Team::SECOND:
		body.setFillColor(Color::Green);
		break;
	default:
		body.setFillColor(Color::White);
		break;
	}
}

void Character::updateAnimations()
{	
	if (velocity.x < 0)
	{
		faceRight = false;
	}
	else if (velocity.x > 0)
	{
		faceRight = true;
	}
	
	animation.update(0, faceRight);
	body.setTextureRect(animation.getuvRect());
}

sf::RectangleShape & Character::getBody()
{
	return body;
}
const sf::Vector2f & Character::getVelocity() const
{
	return velocity;
}

void Character::setOnTheGround(bool state)
{
	onTheGround = state;
}

void Character::stopFalling()
{
	velocity.y = 0;	
	onTheGround = true;
}

void Character::shoot(std::vector<Projectile> & projectiles) 
{	
	if (characterController->getIsShootClicked() && reloadTimer > superGun.reloadTime)
	{		
		projectiles.push_back(Projectile(body.getPosition(), team, superGun, faceRight));
		reloadTimer = 0.0f;
	}	
}

const Team & Character::getTeam() const
{
	return team;
}

void Character::initialForce(float force)
{
	kickVelocity = force;
}

int Character::getLifes() const
{
	return lifes;
}

void Character::reset(const sf::Vector2f & position, bool face)
{
	body.setPosition(position);
	lifes = 3;
	jumpsCount = 0.0f;
	kickVelocity = 0.0f;
	velocity = sf::Vector2f(0, 0);
	faceRight = face;
	onTheGround = false;
}

void Character::updateMove()
{
	velocity.x = speed * characterController.get()->getMoveDirection();
}

void Character::updateJump()
{	
	if (onTheGround)
	{
		jumpsCount = 2;
	}	
	//when falls off the platform by moving sides or down player can jump just once time
	else if (!onTheGround && jumpsCount > 1) 
	{
		jumpsCount = 1;
	}

	if (characterController.get()->getIsJumpClicked() && jumpsCount > 0)
	{
		velocity.y = -sqrtf(jumpPower);
		jumpsCount--;		
		onTheGround = false;
	}	
}

void Character::updateMoveDown()
{
	if (characterController.get()->getIsMoveDownClicked() && onTheGround)
	{
		body.move(sf::Vector2f(0, 8.0f));
	}
}

void Character::updateKick()
{
	if (kickVelocity > 0)
	{
		kickVelocity -= kickReductor;

		if (kickVelocity < 0)
		{
			kickVelocity = 0;
		}
	}
	else if (kickVelocity < 0)
	{
		kickVelocity += kickReductor;

		if (kickVelocity > 0)
		{
			kickVelocity = 0;
		}
	}

	velocity.x += kickVelocity;
}

void Character::updateDead()
{
	if (velocity.y > 30.0f)
	{
		lifes--;
		body.setPosition(sf::Vector2f(respawnParameters.position));
		faceRight = respawnParameters.face;
		velocity.y = 0.0f;
	}
}
