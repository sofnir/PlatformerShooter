#include "Character.h"

Character::Character(unsigned player)
{	
	this->player = player;
	characterController = std::unique_ptr<CharecterController>(new KeyboardController(player));		
	create();	
}

void Character::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
	target.draw(gun);
}

void Character::updateController(sf::Event & event)
{
	characterController.get()->Control(event);	
}

void Character::updateMoving()
{
	move();
	moveDown();
	jump();
	velocity.y += gravity;
	body.move(velocity);

	if (velocity.x < 0)
	{
		faceRight = false;		
	}
	else if(velocity.x > 0)
	{
		faceRight = true;		
	}		
	
	gun.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y));
	gun.setFaceRight(faceRight);
}

void Character::updateCollision(const std::vector<sf::RectangleShape> & platforms)
{
	sf::Vector2f playerPosition = body.getPosition();
	sf::Vector2f playerHalfSize = body.getSize() / 2.0f;
	
	if (velocity.y > 0)
	{
		canJump = false;
		onTheGround = false;

		for (auto & platform : platforms)
		{			
			/* fix bug when jump and intersect with platform which is above and teleport on the platform when 
			foots are still below the platform */
			if (body.getPosition().y + body.getSize().y / 2 > platform.getPosition().y && velocity.y < 5.0f)
			{
				continue;
			}

			sf::Vector2f platformPosition = platform.getPosition();
			sf::Vector2f platformHalfSize = platform.getSize() / 2.0f;

			//calculate distance between cener of objects
			float deltaX = platformPosition.x - playerPosition.x;
			float deltaY = platformPosition.y - playerPosition.y;

			//caluclate intersect of the objects
			float intersectX = abs(deltaX) - (platformHalfSize.x + playerHalfSize.x);
			float intersectY = abs(deltaY) - (platformHalfSize.y + playerHalfSize.y);

			//if objects intersects move objects dependence of the push strenght
			if (intersectX <= 0.0f && intersectY <= 0.0f && intersectX < intersectY && deltaY > 0.0f)
			{
				body.move(0, intersectY);
				velocity.y = 0;
				canJump = true;
				onTheGround = true;
			}
		}
	}	
}

void Character::initialForce(float force)
{
	body.move(force, 0);
}

void Character::setPosition(const sf::Vector2f & position)
{
	body.setPosition(position);
}

sf::FloatRect Character::getGlobalBounds() const
{
	return body.getGlobalBounds();
}

unsigned Character::getPlayer() const
{
	return player;
}

bool Character::isShooting() const
{
	return (characterController.get()->getIsShootClicked() && gun.isReady());
}

Gun & Character::getGun()
{
	return gun;
}

void Character::create()
{		
	body.setSize(sf::Vector2f(40, 40));
	body.setOrigin(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));

	switch (player)
	{
	case 0:
		body.setFillColor(sf::Color::Red);
		break;
	case 1:
		body.setFillColor(sf::Color::Blue);
		break;
	default:
		body.setFillColor(sf::Color::White);
		break;
	}
}

void Character::move()
{	
	velocity.x = speed * characterController.get()->getMoveDirection();	
}

void Character::jump()
{
	if (characterController.get()->getIsJumpClicked() && canJump)
	{
		velocity.y = -sqrtf(jumpPower);
		canJump = false;
		onTheGround = false;		
	}	
}

void Character::moveDown()
{
	if (characterController.get()->getIsMoveDownClicked() && onTheGround)
	{
		body.move(sf::Vector2f(0, 5));
	}
}
