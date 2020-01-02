//*******************************************************
// SudoChoice.h
// Creator: ZhouYifan
// Create Date: 2020/1/2 11:38
// Description:
// Provide the definition of class SudoChoice.
// SudoChoice represent the feasible choices of entrys and
// each number in each palace.
//
// ******************************************************

#ifndef SUDO_CHOICE_H
#define SUDO_CHOICE_H

#include <set>

namespace Sudo
{
	class SudoChoice
	{
	public:
		// enum
		enum Type
		{
			ENTRY,
			NUMBER
		};

		// Constructors

		SudoChoice();
		virtual ~SudoChoice();
		void init(Type type, int posIorNumber, int posJOrPalace);

		// Operator overload
		bool operator<(const SudoChoice& rhs) const { return _feasibleChoices.size() < rhs._feasibleChoices.size(); }
		bool operator>(const SudoChoice& rhs) const { return _feasibleChoices.size() > rhs._feasibleChoices.size(); }

		// Getters and setters
		Type getType() const { return _type; }
		int getPosIOrNumber() const { return _posIOrNumber; }
		int getPosJOrPalace() const { return _posJOrPalace; }

		// functions

		// Delete the choice, return false if it has been delelted
		bool banChoice(int choice);
		// Add the choice, return false if it exists
		bool addChoice(int choice);

	private:
		// Varibale
		Type _type;
		int _posIOrNumber;
		int _posJOrPalace;
		std::set<int> _feasibleChoices;
	};
}


#endif

