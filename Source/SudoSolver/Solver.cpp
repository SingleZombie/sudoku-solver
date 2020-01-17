//*******************************************************
// Solver.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/17 13:21
// Description:
// Provide the implementation of class Solver.
//
// ******************************************************

#include "Solver.h"
#include "SudoSolveAlgorithm.h"

namespace Sudo
{
	Solver::Solver()
	{
	}


	Solver::~Solver()
	{
	}

	bool Solver::solve(SudoMatrix& matrix) const
	{
		return SudoSolveAlgorithm::solve(matrix);
	}
}


