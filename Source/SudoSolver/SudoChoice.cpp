//*******************************************************
// SudoChoice.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/2 14:21
// Description:
// Provide the implement of class SudoChoice.
//
// ******************************************************

#include "SudoChoice.h"
#include "SudoMatrix.h"

namespace Sudo
{
	SudoChoice::SudoChoice()
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
		_feasibleChoices.clear();
	}

	bool SudoChoice::banChoice(int choice)
	{
		if (_feasibleChoices.count(choice))
		{
			_feasibleChoices.erase(choice);
			return true;
		}
		else
		{
			return false;
		}
	}

	bool SudoChoice::addChoice(int choice)
	{
		if (!_feasibleChoices.count(choice))
		{
			_feasibleChoices.insert(choice);
			return true;
		}
		else
		{
			return false;
		}
	}
}

