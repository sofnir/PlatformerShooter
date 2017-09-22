#include "KeyboardController.h"

KeyboardController::KeyboardController(const Keys & type)
{
	if (type == Keys::ARROWS)
	{
		index = 0;
	}
	else if (type == Keys::WSAD)
	{
		index = 1;
	}
}

void KeyboardController::Control(sf::Event & event)
{
	move(event);
	jump(event);
	moveDown(event);
	shoot(event);
}

void KeyboardController::move(sf::Event & event)
{
	if (sf::Keyboard::isKeyPressed(keyMoveLeft[index]))
	{
		moveDirection = MOVE_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(keyMoveRight[index]))
	{
		moveDirection = MOVE_RIGHT;
	}
	else
	{
		moveDirection = MOVE_STOP;
	}
}

void KeyboardController::jump(sf::Event & event)
{
	if (sf::Keyboard::isKeyPressed(keyJump[index]) && canJumpClicked)
	{
		isJumpClicked = true;
		canJumpClicked = false;
	}

	if (event.type == sf::Event::KeyReleased && event.key.code == keyJump[index])
	{
		canJumpClicked = true;
	}
}

void KeyboardController::moveDown(sf::Event & event)
{
	if (sf::Keyboard::isKeyPressed(keyMoveDown[index]) && canMoveDownClicked)
	{
		isMoveDownClicked = true;
		canMoveDownClicked = false;
	}	

	if (event.type == sf::Event::KeyReleased && event.key.code == keyMoveDown[index])
	{
		canMoveDownClicked = true;
	}
}

void KeyboardController::shoot(sf::Event & event)
{
	if (sf::Keyboard::isKeyPressed(keyShoot[index]) && canShootClicked)
	{
		isShootClicked = true;
		canShootClicked = false;
	}
	
	if (event.type == sf::Event::KeyReleased && event.key.code == keyShoot[index])
	{
		canShootClicked = true;
	}
}
