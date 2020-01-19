//*******************************************************
// SudoState.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/1 21:37
// Description:
// Provide the implementation of class SudoState.
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
				_entryChoises[i][j].setAllOne();
				_numberChoises[i][j].init(SudoChoice::Type::NUMBER, i, j);
				_numberChoises[i][j].setAllOne();
			}
		}
	}

	SudoState::~SudoState()
	{

	}

	bool SudoState::fill(const SudoMatrix& mat)
	{
		// It's the first(0) step.
		_step = 0;

		// Create a new matrix
		_mat = SudoMatrix();
		
		// For each entry and number, initialize their state
		for (int i = 0; i < SudoMatrix::SUDO_SIDELENGTH; i++)
		{
			for (int j = 0; j < SudoMatrix::SUDO_SIDELENGTH; j++)
			{
				_entryChoises[i][j].init(SudoChoice::Type::ENTRY, i, j);
				_numberChoises[i][j].init(SudoChoice::Type::NUMBER, i, j);
				if (mat(i, j) == 0)
				{
					_entryChoises[i][j].setAllOne();
				}
				_numberChoises[i][j].setAllOne();
			}
		}

		// For each known number, update the message through setNumber()
		for (int i = 0; i < SudoMatrix::SUDO_SIDELENGTH; i++)
		{
			for (int j = 0; j < SudoMatrix::SUDO_SIDELENGTH; j++)
			{
				if (mat(i, j) != 0)
				{
					if (!setNumber(i, j, mat(i, j), false))
					{
						return false;
					}
				}
			}
		}
		return true;
	}

	bool SudoState::setNumber(int i, int j, int num, bool recordLog)
	{
		assert(_mat(i, j) == 0); // the entry must be empty
		assert(num >= 1 && num <= 9); // number must in 1~9

		int palaceId = SudoMatrix::getPalaceId(i, j);
		int idInPalace = SudoMatrix::getIdInPalace(i, j);

		bool valid = true;
		_mat(i, j) = num;

		_modificationLog[_step].clear();
		if (recordLog)
		{
			_modificationLog[_step].push_back(_entryChoises[i][j]);
			_modificationLog[_step].push_back(_numberChoises[num - 1][palaceId]);
		}
		

		// Ban all the choices in (i, j)
		for (int deletedIndex = 0; deletedIndex < SudoMatrix::SUDO_SIDELENGTH; deletedIndex++)
		{
			_entryChoises[i][j].banChoice(deletedIndex);
			_numberChoises[num - 1][palaceId].banChoice(deletedIndex);
			if (_numberChoises[deletedIndex][palaceId].banChoice(idInPalace) && recordLog)
			{
				SudoChoice newLog;
				newLog.init(SudoChoice::Type::NUMBER, deletedIndex, palaceId);
				newLog.addChoice(idInPalace);
				_modificationLog[_step].push_back(newLog);
			}
		}
		
		// Update the choices of entries with same column
		for (int rowI = 0; rowI < SudoMatrix::SUDO_SIDELENGTH && valid; rowI++)
		{
			if (_mat(rowI, j) == 0)
			{
				int crtPalace = SudoMatrix::getPalaceId(rowI, j);
				int crtIdInPalace = SudoMatrix::getIdInPalace(rowI, j);
				if (_entryChoises[rowI][j].banChoice(num - 1) && recordLog)
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::ENTRY, rowI, j);
					newLog.addChoice(num - 1);
					_modificationLog[_step].push_back(newLog);

					if (_entryChoises[rowI][j].empty())
					{
						valid = false;
					}
				}
				if (_numberChoises[num - 1][crtPalace].banChoice(crtIdInPalace) && recordLog)
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::NUMBER, num - 1, crtPalace);
					newLog.addChoice(crtIdInPalace);
					_modificationLog[_step].push_back(newLog);

					if (_numberChoises[num - 1][crtPalace].empty())
					{
						valid = false;
					}
				}
			}
		}

		// Update the choices of entries with same row
		for (int colJ = 0; colJ < SudoMatrix::SUDO_SIDELENGTH && valid; colJ++)
		{
			if (_mat(i, colJ) == 0)
			{
				int crtPalace = SudoMatrix::getPalaceId(i, colJ);
				int crtIdInPalace = SudoMatrix::getIdInPalace(i, colJ);
				if (_entryChoises[i][colJ].banChoice(num - 1) && recordLog)
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::ENTRY, i, colJ);
					newLog.addChoice(num - 1);
					_modificationLog[_step].push_back(newLog);

					if (_entryChoises[i][colJ].empty())
					{
						valid = false;
					}
				}
				if (_numberChoises[num - 1][crtPalace].banChoice(crtIdInPalace) && recordLog)
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::NUMBER, num - 1, crtPalace);
					newLog.addChoice(crtIdInPalace);
					_modificationLog[_step].push_back(newLog);

					if (_numberChoises[num - 1][crtPalace].empty())
					{
						valid = false;
					}
				}
			}
		}

		// Update the choices of entries with same palace
		for (int palI = 0; palI < SudoMatrix::SUDO_SIDELENGTH && valid; palI++)
		{
			if (_mat.getNumPalace(palaceId, palI) == 0)
			{
				int row = (palaceId / 3) * 3 + (palI / 3);
				int col = (palaceId % 3) * 3 + (palI % 3);
				if (_entryChoises[row][col].banChoice(num - 1) && recordLog)
				{
					SudoChoice newLog;
					newLog.init(SudoChoice::Type::ENTRY, row, col);
					newLog.addChoice(num - 1);
					_modificationLog[_step].push_back(newLog);
				}
			}
		}

		_step++;
		return valid;
	}

	SudoChoice SudoState::getMinForkOperation()
	{
		SudoChoice minChoice;
		bool find = false;
		for (int i = 0; i < SudoMatrix::SUDO_SIDELENGTH; i++)
		{
			for (int j = 0; j < SudoMatrix::SUDO_SIDELENGTH; j++)
			{
				if (!_entryChoises[i][j].empty())
				{
					if (!find || _entryChoises[i][j] < minChoice)
					{
						minChoice = _entryChoises[i][j];
						find = true;
					}
				}
				if (!_numberChoises[i][j].empty())
				{
					if (!find || _numberChoises[i][j] < minChoice)
					{
						minChoice = _numberChoises[i][j];
						find = true;
					}
				}
			}
		}
		return minChoice;
	}

	void SudoState::recall()
	{
		assert(_step >= 0);
		_step--;
		for (auto& choiceSet : _modificationLog[_step])
		{
			int i = choiceSet.getPosIOrNumber();
			int j = choiceSet.getPosJOrPalace();
			if (choiceSet.getType() == SudoChoice::ENTRY)
			{
				// ENTRY
				_entryChoises[i][j].recover(choiceSet);
			}
			else if (choiceSet.getType() == SudoChoice::NUMBER)
			{
				// NUMBER
				_numberChoises[i][j].recover(choiceSet);
			}
			else
			{
				assert(false);
			}
		}
		int posI = _modificationLog[_step][0].getPosIOrNumber();
		int posJ = _modificationLog[_step][0].getPosJOrPalace();
		_mat(posI, posJ) = 0;
	}
}


