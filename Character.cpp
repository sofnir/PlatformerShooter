#include "Character.h"

Character::Character()
{
	characterController = std::unique_ptr<CharecterController>(new KeyboardController());
	body.setSize(sf::Vector2f(40, 40));
	body.setPosition(sf::Vector2f(400, 100));
	body.setOrigin(sf::Vector2f(20, 20));
}

void Character::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(body);
}

void Character::update()
{
	characterController.get()->Control();
	move();
	jump();
	velocity.y += gravity;
	body.move(velocity);
}

void Character::checkCollision(const std::vector<sf::RectangleShape> & platforms)
{
	sf::Vector2f playerPosition = body.getPosition();
	sf::Vector2f playerHalfSize = body.getSize() / 2.0f;
	
	if (velocity.y > 0)
	{
		for (auto & platform : platforms)
		{
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
			}
		}
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
	}
}
