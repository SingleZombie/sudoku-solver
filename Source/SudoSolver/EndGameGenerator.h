//*******************************************************
// EndGameGenerator.h
// Creator: ZhouYifan
// Create Date: 2020/1/17 13:24
// Description:
// Provide the definition of class EndGameGenerator
// EndGameGenerator generates a sudoku end-game from a 
// sudoku final state with specific difficulty.
//
// ******************************************************

#ifndef END_GAME_GENERATOR_H
#define END_GAME_GENERATOR_H

#include "SudoMatrix.h"

namespace Sudo
{
	class EndGameGenerator
	{
	public:
		enum Difficulty
		{
			EASY,
			MIDDLE,
			HARD
		};
		EndGameGenerator();
		virtual ~EndGameGenerator();
		SudoMatrix generateEndGame(const SudoMatrix& finalState, Difficulty difficulty = MIDDLE, int seed = 123456) const;
	};
}

#endif

