#pragma once
#include "Character.h"

class Logic
{
public:
	Logic();

	enum class LogicState
	{
		PLAYING,
		GAME_OVER
	};
	
	void updateLogic(std::vector<Character> & players);
	const LogicState & getCurrentState() const;
	const Team & getWinner() const;
	void reset();

private:
	LogicState currentState;
	Team winner;
};
