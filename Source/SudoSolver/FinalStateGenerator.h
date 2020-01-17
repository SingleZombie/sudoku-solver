//*******************************************************
// FinalStateGenerator.h
// Creator: ZhouYifan
// Create Date: 2020/1/17 12:43
// Description:
// Provide the definition of class FinalStateGenerator.
// FinalStateGenerator can generate a sudoku whose entries
// have been fiiled.
//
// ******************************************************

#ifndef FINAL_STATE_GENERATOR_H
#define FINAL_STATE_GENERATOR_H

#include "SudoMatrix.h"
namespace Sudo
{
	class FinalStateGenerator
	{
	public:
		FinalStateGenerator();
		virtual ~FinalStateGenerator();

		// Generate matrices of specific count and stored in pre-allocated array. 
		// The max count is 2e6 if the first number is fixed.
		// Otherwise the max count is 1.8e7.
		// Return the actual count of generated matrices.
		int generateFinalState(int count, Sudo::SudoMatrix* matrixArr, int fixFirstNumber = 0) const;
	};
}

#endif

