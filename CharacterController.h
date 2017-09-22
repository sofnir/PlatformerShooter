#pragma once
#include <SFML/Window/Event.hpp>
#include <iostream>

class CharecterController
{
public:
	CharecterController();
	virtual ~CharecterController() = default;

	virtual void Control(sf::Event & event) = 0;

	float getMoveDirection() const;
	bool getIsJumpClicked();
	bool getIsMoveDownClicked();
	bool getIsShootClicked();

protected:	
	float moveDirection = 0.0f;

	bool isJumpClicked = false;
	bool canJumpClicked = true;

	bool isMoveDownClicked = false;
	bool canMoveDownClicked = true;

	bool isShootClicked = false;
	bool canShootClicked = true;
};