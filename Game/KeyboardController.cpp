#include "KeyboardController.h"

KeyboardController::KeyboardController(unsigned player) : currentPlayer(player)
{
	;
}

void KeyboardController::Control(sf::Event & event)
{
	if (sf::Keyboard::isKeyPressed(keyMoveLeft[currentPlayer]))
	{
		moveDirection = MOVE_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(keyMoveRight[currentPlayer]))
	{
		moveDirection = MOVE_RIGHT;
	}
	else
	{
		moveDirection = MOVE_STOP;
	}

	if (sf::Keyboard::isKeyPressed(keyJump[currentPlayer]))
	{		
		isJumpClicked = true;	
	}
	else
	{
		isJumpClicked = false;
	}

	if (sf::Keyboard::isKeyPressed(keyMoveDown[currentPlayer]))
	{
		isMoveDownClicked = true;
	}
	else
	{
		isMoveDownClicked = false;
	}
	
	if (sf::Keyboard::isKeyPressed(keyShoot[currentPlayer]))
	{
		isShootClicked = true;
	}	
	else
	{
		isShootClicked = false;
	}
}
