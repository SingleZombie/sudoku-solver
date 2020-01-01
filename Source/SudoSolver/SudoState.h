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

namespace Sudo
{
	class SudoState
	{
	public:
		SudoState();
		virtual ~SudoState();
	};
}



#endif

