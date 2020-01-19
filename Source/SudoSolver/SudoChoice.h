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
#include <bitset>

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
		SudoChoice(const SudoChoice& choice);
		virtual ~SudoChoice();
		void init(Type type, int posIorNumber, int posJOrPalace);
		void setAllOne();

		// Operator overload

		// Compare the size of choices set
		bool operator<(const SudoChoice& rhs) const { return _cnt < rhs._cnt; }
		bool operator>(const SudoChoice& rhs) const { return _cnt > rhs._cnt; }

		// Getters and setters
		Type getType() const { return _type; }
		int getPosIOrNumber() const { return _posIOrNumber; }
		int getPosJOrPalace() const { return _posJOrPalace; }
		bool empty() const { return _cnt == 0; }
		std::set<int> getChoices() const;

		// functions

		// Delete the choice, return false if it has been delelted
		bool banChoice(int choice);
		// Add the choice, return false if it exists
		bool addChoice(int choice);
		// Recover the choices from a log
		void recover(const SudoChoice& log);

	private:
		// Varibale
		Type _type;
		int _posIOrNumber;
		int _posJOrPalace;
		int _cnt;
		std::bitset<9> _feasibleChoices;
	};
}


#endif

