//*******************************************************
// EndGameGenerator.h
// Creator: ZhouYifan
// Create Date: 2020/1/17 13:26
// Description:
// Provide the implementation of class EndGameGenerator.
//
// ******************************************************

#include "EndGameGenerator.h"
#include "SudoEndGameAlgorithm.h"

namespace Sudo
{
	EndGameGenerator::EndGameGenerator()
	{
	}


	EndGameGenerator::~EndGameGenerator()
	{
	}

	SudoMatrix EndGameGenerator::generateEndGame(const SudoMatrix& finalState, Difficulty difficulty, int seed) const
	{
		switch (difficulty)
		{
		case EASY:
			return SudoEndGameAlgorithm::getEndGame(finalState, 2, 20, seed);
		case MIDDLE:
			return SudoEndGameAlgorithm::getEndGame(finalState, 2, 40, seed);
		case HARD:
			return SudoEndGameAlgorithm::getEndGame(finalState, 3, 60, seed);
		default:
			throw "difficulty error";
		}
	}
}


