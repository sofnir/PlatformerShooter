#include "KeyboardController.h"

KeyboardController::KeyboardController()
{
	moveDirection = 0.0f;
	isJumpClicked = false;
	controllerType = "KEYBOARD";
}

void KeyboardController::Control()
{
	if (sf::Keyboard::isKeyPressed(keyMoveLeft))
	{
		moveDirection = MOVE_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(keyMoveRight))
	{
		moveDirection = MOVE_RIGHT;
	}
	else
	{
		moveDirection = MOVE_STOP;
	}

	if (sf::Keyboard::isKeyPressed(keyJump))
	{		
		isJumpClicked = true;	
	}
	else
	{
		isJumpClicked = false;
	}
}

std::string KeyboardController::getControllerType()
{
	return controllerType;
}

float KeyboardController::getMoveDirection()
{
	return moveDirection;
}

bool KeyboardController::getIsJumpClicked()
{	
	return isJumpClicked;
}
