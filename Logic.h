#pragma once
#include "Character.h"

class Logic
{
public:
	Logic();

	enum class LogicState
	{
		PLAYING,
		FIRST_TEAM_WIN,
		SECOND_TEAM_WIN,
		DRAW		
	};
	
	bool isAnyPlayerDead(std::vector<Character> & players) const;
	void update(std::vector<Character> & players);
	const LogicState & getCurrentState() const;	
	void reset();

private:
	LogicState currentState;	
};

//if anyone dead
//{
//	create timer;
//}
//
//if timer end
//{
//	who is alive ?
//	{
//		noone - draw;
//		somone - somone win;
//	}
//	delete timer;
//}
