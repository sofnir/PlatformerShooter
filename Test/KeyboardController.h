#pragma once
#include "CharacterController.h"
#include <iostream>

class KeyboardController : public CharecterController
{
public:
	KeyboardController(unsigned player);

	void Control(sf::Event & event) override;

private:
	const float MOVE_LEFT = -1.0f;
	const float MOVE_RIGHT = 1.0f;
	const float MOVE_STOP = 0.0f;

	unsigned currentPlayer = 0;
	
	sf::Keyboard::Key keyMoveLeft[2] = { sf::Keyboard::Left, sf::Keyboard::A };
	sf::Keyboard::Key keyMoveRight[2] = { sf::Keyboard::Right, sf::Keyboard::D };
	sf::Keyboard::Key keyMoveDown[2] = { sf::Keyboard::Down, sf::Keyboard::S };
	sf::Keyboard::Key keyJump[2] = { sf::Keyboard::Up, sf::Keyboard::W };
	sf::Keyboard::Key keyShoot[2] = { sf::Keyboard::Return, sf::Keyboard::Space };
};