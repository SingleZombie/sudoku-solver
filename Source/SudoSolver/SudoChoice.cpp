//*******************************************************
// SudoChoice.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/2 14:21
// Description:
// Provide the implementation of class SudoChoice.
//
// ******************************************************

#include "SudoChoice.h"
#include "SudoMatrix.h"

namespace Sudo
{
	SudoChoice::SudoChoice() :
		_type(Type::ENTRY),
		_posIOrNumber(-1),
		_posJOrPalace(-1),
		_feasibleChoices(),
		_cnt(0)
	{
		
	}

	SudoChoice::SudoChoice(const SudoChoice& choice) :
		_type(choice._type),
		_posIOrNumber(choice._posIOrNumber),
		_posJOrPalace(choice._posJOrPalace),
		_feasibleChoices(choice._feasibleChoices),
		_cnt(choice._cnt)
	{

	}


	SudoChoice::~SudoChoice()
	{

	}

	void SudoChoice::init(Type type, int posIorNumber, int posJOrPalace)
	{
		_type = type;
		_posIOrNumber = posIorNumber;
		_posJOrPalace = posJOrPalace;
	}

	void SudoChoice::setAllOne()
	{
		_feasibleChoices = std::bitset<9>("111111111");
		_cnt = 9;
	}

	bool SudoChoice::banChoice(int choice)
	{
		if (_feasibleChoices[choice])
		{
			_feasibleChoices[choice] = 0;
			_cnt--;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool SudoChoice::addChoice(int choice)
	{
		if (!_feasibleChoices[choice])
		{
			_feasibleChoices[choice] = 1;
			_cnt++;
			return true;
		}
		else
		{
			return false;
		}
	}

	void SudoChoice::recover(const SudoChoice& log)
	{
		assert(_type == log._type);
		assert(_posIOrNumber == log._posIOrNumber);
		assert(_posJOrPalace == log._posJOrPalace);
		
		_feasibleChoices |= log._feasibleChoices;
		_cnt = _feasibleChoices.count();
	}

	std::set<int> SudoChoice::getChoices() const
	{
		std::set<int> set;
		for (int i = 0; i < SudoMatrix::SUDO_SIDELENGTH; i++)
		{
			if (_feasibleChoices[i])
			{
				set.insert(i);
			}
		}
		return set;
	}
}

