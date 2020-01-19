//*******************************************************
// SuduSolveAlgorithm.h
// Creator: ZhouYifan
// Create Date: 2020/1/10 14:00
// Description:
// Provide the implementation of class SudoSolveAlgorithm.
//
// ******************************************************

#include "SudoSolveAlgorithm.h"

namespace Sudo
{
	SudoState SudoSolveAlgorithm::_sudoState;

	SudoSolveAlgorithm::SudoSolveAlgorithm()
	{

	}


	SudoSolveAlgorithm::~SudoSolveAlgorithm()
	{
		
	}

	bool SudoSolveAlgorithm::solve(SudoMatrix& mat)
	{
		// Fill the matrix with known message
		if (!fillState(mat))
		{
			return false;
		}
		// Use dfs to find the solution
		if (!dfs())
		{
			return false;
		}
		// Get result
		mat = _sudoState.getMat();
		return true;
	}

	bool SudoSolveAlgorithm::dfs()
	{
		if (_sudoState.getStep() >= SudoMatrix::SUDO_ELEMENTS_CNT)
		{
			return true;
		}

		const auto& op = _sudoState.getMinForkOperation();

		if (op.getType() == SudoChoice::ENTRY)
		{
			// ENRTY
			const auto& set = op.getChoices();
			for (auto num : set)
			{
				bool yes = false;
				if (_sudoState.setNumber(op.getPosIOrNumber(), op.getPosJOrPalace(), num + 1))
				{
					if (dfs())
					{
						yes = true;
					}
				}
				if (!yes)
				{
					_sudoState.recall();
				}
				else
				{
					return true;
				}
			}
		}
		else
		{
			// NUMBER
			const auto& set = op.getChoices();
			for (auto pos : set)
			{
				bool yes = false;
				int i = SudoMatrix::getIFromPalacePos(op.getPosJOrPalace(), pos);
				int j = SudoMatrix::getJFromPalacePos(op.getPosJOrPalace(), pos);
				if (_sudoState.setNumber(i, j, op.getPosIOrNumber() + 1))
				{
					if (dfs())
					{
						yes = true;
					}
				}
				if (!yes)
				{
					_sudoState.recall();
				}
				else
				{
					return true;
				}
			}
		}

		return false;
	}
	bool SudoSolveAlgorithm::fillState(const SudoMatrix& mat)
	{
		return _sudoState.fill(mat);
	}
}


