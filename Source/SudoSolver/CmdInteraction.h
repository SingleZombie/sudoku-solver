//*******************************************************
// CmdInteraction.h
// Creator: ZhouYifan
// Create Date: 2020/1/17 14:09
// Description:
// Provide the definition of class CmdInteraction.
// CmdInteraction loads input from command line and
// call other objects to address the commands.
//
// ******************************************************

#ifndef CMD_INTERACTION_H
#define CMD_INTERACTION_H

#include "Solver.h"
#include "EndGameGenerator.h"
#include "FinalStateGenerator.h"
#include "SudoMatrixIO.h"

namespace Sudo
{
	class CmdInteraction
	{
	public:
		CmdInteraction();
		virtual ~CmdInteraction();

		bool inputCmd(int argc, char* argv[]);
	private:
		Solver _solver;
		EndGameGenerator _endGameGenerator;
		FinalStateGenerator _finalStateGenerator;

		bool processCmd(char* cmdText, char* argPtr[]);
		bool generateSudoku(char* arg[]);
		bool solveSudoku(char* arg[]);
	};
}

#endif

