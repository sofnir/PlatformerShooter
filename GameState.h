#pragma once
#include "Game.h"

class GameState
{
public:	
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void handleInput() = 0;

	virtual ~GameState() = default;

protected:
	Game* game;
};
