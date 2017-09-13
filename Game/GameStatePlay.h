#pragma once
#include <SFML/Window/Event.hpp>
#include "GameState.h"
#include "Map.h"
#include "Character.h"
#include "ProjectilesManager.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game * game);

	void draw() override;
	void update() override;
	void handleInput() override;

private:
	Map map;
	ProjectilesManager projectilesManager;
	std::vector<Character> players;

	void createPlayers();
};