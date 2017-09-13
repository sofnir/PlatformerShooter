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
	std::string getControllerType() const;

protected:
	std::string controllerType = "KEYBOARD";
	float moveDirection = 0.0f;
	bool isJumpClicked = false;
	bool isMoveDownClicked = false;
	bool isShootClicked = false;
};