#pragma once
#include <SFML/Window/Event.hpp>
#include "GameState.h"

class GameStateMenu : public GameState
{

public:
	GameStateMenu(Game* game);

	void draw() override;
	void update() override;
	void handleInput() override;

private:
	void playGame();
};