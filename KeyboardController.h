#pragma once
#include "CharacterController.h"
#include "SFML/Window/Event.hpp"

class KeyboardController : public CharecterController
{
public:
	KeyboardController();
	
	void Control() override;

	std::string getControllerType();
	float getMoveDirection();
	bool getIsJumpClicked();

private:
	const float MOVE_LEFT = -1.0f;
	const float MOVE_RIGHT = 1.0f;
	const float MOVE_STOP = 0.0f;

	sf::Keyboard::Key keyMoveLeft = sf::Keyboard::Left;
	sf::Keyboard::Key keyMoveRight = sf::Keyboard::Right;
	sf::Keyboard::Key keyJump = sf::Keyboard::Space;
};