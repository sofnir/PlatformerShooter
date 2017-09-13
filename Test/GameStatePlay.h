#pragma once
#include <SFML/Window/Event.hpp>
#include "GameState.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game * game);

	void draw() override;
	void update() override;
	void handleInput() override;
};