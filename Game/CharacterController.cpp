#include "CharacterController.h"

CharecterController::CharecterController()
{
	;
}

float CharecterController::getMoveDirection() const
{
	return moveDirection;
}

bool CharecterController::getIsJumpClicked() 
{
	if (isJumpClicked)
	{
		isJumpClicked = false;
		return true;
	}
	else
	{
		return false;
	}	
}

bool CharecterController::getIsMoveDownClicked()
{
	if (isMoveDownClicked)
	{
		isMoveDownClicked = false;
		return true;
	}
	else
	{
		return false;
	}	
}

bool CharecterController::getIsShootClicked()
{	
	if (isShootClicked)
	{
		isShootClicked = false;
		return true;
	}
	else
	{
		return false;
	}	
}

std::string CharecterController::getControllerType() const
{
	return controllerType;
}
