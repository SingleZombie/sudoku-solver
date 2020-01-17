//*******************************************
// SudoMatrix.h
// Creator: ZhouYifan
// Create Date: 2020/1/17 10:05
// Description:
// Provide the definition of class SudoEndGameAlgorithm.
// SudoEndGameAlgorithm provides algorithm which genereate
// sudoku end-game by removing some entries of a sudoku final
// state.
//
// ******************************************************

#ifndef SUDO_ENDGAME_ALGORITHM_H
#define SUDO_ENDGAME_ALGORITHM_H
#include "SudoMatrix.h"
namespace Sudo
{
	class SudoEndGameAlgorithm
	{
	public:
		static SudoMatrix getEndGame(
			const SudoMatrix& sudokuFinalState,
			int minEmptyEntryPerPalace,
			int totalEmptyEntryCount,
			int seed = 123456);
	private:
		SudoEndGameAlgorithm();
		virtual ~SudoEndGameAlgorithm();
	};
}

#endif

