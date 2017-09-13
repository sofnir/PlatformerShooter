#pragma once
#include "Game.h"

class GameState
{
public:	
	virtual ~GameState() = default;

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void handleInput() = 0;

protected:
	Game* game;
};
