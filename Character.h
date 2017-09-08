#pragma once
#include "CharacterController.h"
#include "KeyboardController.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>
#include <vector>

class Character : public sf::Drawable
{
public:
	Character();
	virtual ~Character() = default;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	enum class CharacterType
	{
		NONE, PLAYER, ENEMY, OTHER
	};

	enum class ControllerType
	{
		KEYBOARD, AI
	};

	void update();
	void checkCollision(const std::vector<sf::RectangleShape> & platforms);

protected:	
	sf::Vector2f velocity = sf::Vector2f(0, 0);
	float speed = 5.0f;
	float gravity = 0.4f;
	float jumpPower = 100.0f;
	bool canJump = false;
	CharacterType characterType = CharacterType::NONE;
	ControllerType controllerType = ControllerType::KEYBOARD;
	std::unique_ptr<CharecterController> characterController;
	sf::RectangleShape body;

	virtual void move();
	virtual void jump();
};
