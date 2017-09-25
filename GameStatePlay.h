#pragma once
#include <SFML/Window/Event.hpp>
#include "GameState.h"
#include "Map.h"
#include "Character.h"
#include "Collision.h"
#include "CharacterGUI.h"
#include "Logic.h"
#include "Dialog.h"
#include "Timer.h"

class GameStatePlay : public GameState
{
public:
	GameStatePlay(Game * game);

	void draw() override;
	void update(float dt) override;
	void handleInput() override;

private:	
	Map map;	
	Logic logic;
	Collision collision;
	std::unique_ptr<Timer> timer;
	std::unique_ptr<Dialog> dialog;
	std::vector<Character> players;	
	std::vector<CharacterGUI> playersGUI;
	std::vector<Projectile> projectiles;	

	void createPlayers();
	void createGui();
};