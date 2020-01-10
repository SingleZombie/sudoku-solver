//*******************************************************
// SudoState.h
// Creator: ZhouYifan
// Create Date: 2020/1/1 21:34
// Description:
// Provide the definition of class SudoState.
// SudoMatrix is a class that records the extra information
// of a sudoku including the feasible position of each number
// in each palace and the feasible number of each position.
// It also saves the modify log which makes rewind opeation
// avaliable.
//
// ******************************************************

#ifndef SUDO_STATE_H
#define SUDO_STATE_H

#include "SudoMatrix.h"
#include "SudoChoice.h"

#include <vector>
#include <cassert>

namespace Sudo
{
	class SudoState
	{
	public:
		SudoState();
		virtual ~SudoState();

		// Fill the blank entry of sudoku matrix. 
		// Return false if no solution after the 
		// operation.
		bool setNumber(int i, int j, int num);

		// Get feasible choices of a number in a palace 
		// or an entry with minimun  which makes the dfs
		// fork as least as possible.
		SudoChoice getMinForkOperation();

		// Cancel the previous operation(add the choices back
		// which have been deleted in the previous step from
		// modification log)
		void recall();

		unsigned getStep() { return _step; }
		SudoMatrix getMat() { return _mat; }
	private:
		// Functions

		// Varibles

		unsigned _step;
		SudoMatrix _mat;
		SudoChoice _numberChoises[SudoMatrix::SUDO_SIDELENGTH][SudoMatrix::SUDO_SIDELENGTH];
		SudoChoice _entryChoises[SudoMatrix::SUDO_SIDELENGTH][SudoMatrix::SUDO_SIDELENGTH];

		// Record the choices which were deleted in the previous step
		// Specially, the first logs is the entry which was filled in
		// the previous step.
		std::vector<SudoChoice> _modificationLog[SudoMatrix::SUDO_ELEMENTS_CNT];
	};
}



#endif

