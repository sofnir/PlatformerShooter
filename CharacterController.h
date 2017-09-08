#pragma once
#include <iostream>

class CharecterController
{
public:
	virtual ~CharecterController() = default;

	virtual void Control() = 0;

	float getMoveDirection() const;
	bool getIsJumpClicked() const;

protected:
	std::string controllerType;
	float moveDirection;
	bool isJumpClicked;	
};