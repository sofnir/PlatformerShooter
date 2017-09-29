#include "Character.h"

Character::Character(const Team & team, CharecterController * controller, const RespawnParameters & respawn)
	: animation(sf::Vector2f(32, 32), 0.1)
{	
	this->team = team;
	characterController = std::unique_ptr<CharecterController>(controller);
	currentLifes = startingLifes;
	respawnParameters.position = respawn.position;
	faceRight = respawnParameters.face = respawn.face;		

	createBody();
	createAnimations();
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
	body.setSize(sf::Vector2f(96, 96));
	body.setOrigin(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));
	body.setTexture(& Data::playerTexture);
	body.setPosition(respawnParameters.position);	
}

void Character::createAnimations()
{
	animation.createAnimation("Iddle", 0, 5);
	animation.createAnimation("Run", 1, 10);
	animation.createAnimation("Jump", 2, 9);
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

	if(velocity.x != 0 && onTheGround)
	{
		animation.setCurrentAnimation("Run");
	}
	else if (velocity.x == 0 && onTheGround)
	{
		animation.setCurrentAnimation("Iddle");
	}
	else if (!onTheGround)
	{
		animation.setCurrentAnimation("Basic");
	}

	animation.update(faceRight);
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
	return currentLifes;
}

void Character::reset()
{
	body.setPosition(respawnParameters.position);
	faceRight = respawnParameters.face;
	currentLifes = startingLifes;
	jumpsCount = 0.0f;
	kickVelocity = 0.0f;
	velocity = sf::Vector2f(0, 0);	
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
	if (currentLifes > 0 && velocity.y > 30.0f)
	{
		currentLifes--;

		if (currentLifes > 0)
		{
			body.setPosition(sf::Vector2f(respawnParameters.position));
			faceRight = respawnParameters.face;
		}			

		velocity.y = 0.0f;
	}
}
