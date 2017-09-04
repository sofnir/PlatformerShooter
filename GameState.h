#pragma once
#include "Game.h"

class GameState
{
public:
	Game* game;

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void handleInput() = 0;
};
