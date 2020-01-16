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
	SudoChoice::SudoChoice()
	{
		
	}

	SudoChoice::SudoChoice(const SudoChoice& choice) :
		_type(choice._type),
		_posIOrNumber(choice._posIOrNumber),
		_posJOrPalace(choice._posJOrPalace),
		_feasibleChoices(choice._feasibleChoices)
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

	void SudoChoice::recover(const SudoChoice& log)
	{
		assert(_type == log._type);
		assert(_posIOrNumber == log._posIOrNumber);
		assert(_posJOrPalace == log._posJOrPalace);

		for (auto num : log._feasibleChoices)
		{
			_feasibleChoices.insert(num);
		}
	}
}

