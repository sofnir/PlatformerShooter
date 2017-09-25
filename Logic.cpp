#include "Logic.h"

Logic::Logic()
{
	currentState = LogicState::PLAYING;
}

bool Logic::isAnyPlayerDead(std::vector<Character> & players) const
{
	for (auto & player : players)
	{
		if (player.getLifes() <= 0)
		{						
			return true;
		}
	}

	return false;
}

void Logic::update(std::vector<Character> & players)
{
	currentState = LogicState::DRAW;

	for (auto & player : players)
	{
		if (player.getLifes() > 0)
		{			
			if (player.getTeam() == Team::FIRST)
			{
				currentState = LogicState::FIRST_TEAM_WIN;
			}
			else
			{
				currentState = LogicState::SECOND_TEAM_WIN;
			}			
		}
	}
}

const Logic::LogicState & Logic::getCurrentState() const
{
	return currentState;
}

void Logic::reset()
{
	currentState = LogicState::PLAYING;
}
