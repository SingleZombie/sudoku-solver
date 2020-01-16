//*******************************************************
// SudoSolveAlgorithm.h
// Creator: ZhouYifan
// Create Date: 2020/1/10 14:00
// Description:
// Provide the definition of class SudoSolveAlgorithm.
// SudoSolveAlgorithm is a static class which provide the
// algorithm to solve the sudoku.
//
// ******************************************************

#ifndef SUDO_SOLVE_ALGORITHM
#define SUDO_SOLVE_ALGORITHM

#include "SudoState.h"

namespace Sudo
{
	class SudoSolveAlgorithm
	{
	public:
		// return true if the sudoku has solution
		static bool solve(SudoMatrix& mat);
	private:
		SudoSolveAlgorithm();
		~SudoSolveAlgorithm();

		static bool dfs();
		static bool fillState(const SudoMatrix& mat);

		static SudoState _sudoState;
	};
}

#endif

