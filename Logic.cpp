#include "Logic.h"

Logic::Logic()
{
	currentState = LogicState::PLAYING;
}

void Logic::updateLogic(std::vector<Character> & players)
{
	for (auto & player : players)
	{
		if (player.getLifes() <= 0)
		{
			currentState = LogicState::GAME_OVER;

			if (player.getTeam() == Team::FIRST)
			{
				winner = Team::SECOND;
			}
			else
			{
				winner = Team::FIRST;
			}
			
		}
	}
}

const Logic::LogicState & Logic::getCurrentState() const
{
	return currentState;
}

const Team & Logic::getWinner() const
{
	return winner;
}

void Logic::reset()
{
	currentState = LogicState::PLAYING;
}
