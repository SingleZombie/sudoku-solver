//*******************************************************
// SudoState.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/1 21:37
// Description:
// Provide the implement of class SudoState.
//
// ******************************************************

#include "SudoState.h"

namespace Sudo
{
	SudoState::SudoState() :
		_step(0),
		_mat()
	{
		for (int i = 0; i < SudoMatrix::SUDO_SIDELENGTH; i++)
		{
			for (int j = 0; j < SudoMatrix::SUDO_SIDELENGTH; j++)
			{
				_entryChoises[i][j].init(SudoChoice::Type::ENTRY, i, j);
				_numberChoises[i][j].init(SudoChoice::Type::NUMBER, i, j);
				for (int num = 1; num <= SudoMatrix::SUDO_SIDELENGTH; num++)
				{
					_entryChoises[i][j].addChoice(num);
					_numberChoises[i][j].addChoice(num - 1);
				}
			}
		}
	}

	SudoState::~SudoState()
	{

	}

	bool SudoState::setNumber(int i, int j, int num)
	{
		assert(_mat(i, j) == 0); // the entry must be empty
		assert(num >= 1 && num <= 9); // number must in 1~9

		int palaceId = SudoMatrix::getPalaceId(i, j);

		bool valid = true;
		_mat(i, j) = num;

		_modificationLog[_step].push_back(_entryChoises[i][j]);
		_modificationLog[_step].push_back(_numberChoises[num][palaceId]);

		for (int deletedIndex = 0; deletedIndex < SudoMatrix::SUDO_SIDELENGTH; deletedIndex++)
		{
			_entryChoises[i][j].banChoice(deletedIndex + 1);
			_numberChoises[num][palaceId].banChoice(deletedIndex);
		}
		

		for (int rowI = 0; rowI < SudoMatrix::SUDO_SIDELENGTH; rowI++)
		{
			if (_mat(rowI, j) == 0)
			{
				int crtPalace = SudoMatrix::getPalaceId(rowI, j);
				int crtIdInPalace = SudoMatrix::getIdInPalace(rowI, j);
				if (_entryChoises[rowI][j].banChoice(num))
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::ENTRY, rowI, j);
					newLog.addChoice(num);
					_modificationLog[_step].push_back(newLog);
				}
				if (_numberChoises[num][crtPalace].banChoice(crtIdInPalace))
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::NUMBER, num, crtPalace);
					newLog.addChoice(crtIdInPalace);
					_modificationLog[_step].push_back(newLog);
				}
			}
		}

		for (int colJ = 0; colJ < SudoMatrix::SUDO_SIDELENGTH; colJ++)
		{
			if (_mat(i, colJ) == 0)
			{
				int crtPalace = SudoMatrix::getPalaceId(i, colJ);
				int crtIdInPalace = SudoMatrix::getIdInPalace(i, colJ);
				if (_entryChoises[i][colJ].banChoice(num))
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::ENTRY, i, colJ);
					newLog.addChoice(num);
					_modificationLog[_step].push_back(newLog);
				}
				if (_numberChoises[num][crtPalace].banChoice(crtIdInPalace))
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::NUMBER, num, crtPalace);
					newLog.addChoice(crtIdInPalace);
					_modificationLog[_step].push_back(newLog);
				}
			}
		}

		
		for (int palI = 0; palI < SudoMatrix::SUDO_SIDELENGTH; palI++)
		{
			if (_mat.getNumPalace(palaceId, palI) == 0)
			{
				int row = (palaceId / 3) * 3 + (palI / 3);
				int col = (palaceId % 3) * 3 + (palI % 3);
				if (_entryChoises[row][col].banChoice(num))
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::ENTRY, row, col);
					newLog.addChoice(num);
					_modificationLog[_step].push_back(newLog);
				}
			}
		}


	}

	SudoChoice SudoState::getMinForkOperation()
	{
		
	}
}


