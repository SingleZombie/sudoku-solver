//*******************************************************
// Solver.h
// Creator: ZhouYifan
// Create Date: 2020/1/17 13:19
// Description:
// Provide the definition of class Solver.
// Solver can solve a matrix containing empty entries.
//
// ******************************************************
#ifndef SOLVER_H
#define SOLVER_H
#include "SudoMatrix.h"
namespace Sudo
{
	class Solver
	{
	public:
		Solver();
		virtual ~Solver();
		bool solve(SudoMatrix& matrix) const;
	};
}

#endif

