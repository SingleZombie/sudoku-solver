//*******************************************************
// SudoMatrix.h
// Creator: ZhouYifan
// Create Date: 2020/1/1 20:53
// Description:
// Provide the definition of class SudoMatrix.
// SudoMatrix is a class that records the 81 elements of sudoku.
// Data are stored in a char array. It's seemed that they are
// stored in a 2D array.
//
// ******************************************************

#ifndef SUDO_MATRIX_H
#define SUDO_MATRIX_H

namespace Sudo
{
	class SudoMatrix
	{
	public:

		// Constructors

		SudoMatrix();
		SudoMatrix(char* sudoTexts);
		SudoMatrix(int* sudoArrays);
		virtual ~SudoMatrix();

		// functions

		bool valid() const;
		void output() const;

		// inline functions

		char getNum(int i, int j) const
		{
			return data[getIndex(i, j)];
		}

		void setNum(int i, int j, char num)
		{
			data[getIndex(i, j)] = num;
		}

		char getNumPalace(int i, int j) const
		{
			return data[getIndex((i / 3) * 3 + (j / 3) , (i % 3) * 3 + (j % 3))];
		}

		void setNumPalace(int i, int j, char num)
		{
			data[getIndex((i / 3) * 3 + (j / 3), (i % 3) * 3 + (j % 3))] = num;
		}

		char operator()(int i, int j) const
		{
			return data[getIndex(i, j)];
		}

		char& operator()(int i, int j)
		{
			return data[getIndex(i, j)];
		}

		// Variables

		// Constants
		static const unsigned SUDO_SIDELENGTH = 9;
		static const unsigned SUDO_ELEMENTS_CNT = SUDO_SIDELENGTH * SUDO_SIDELENGTH;
	private:

		// inline functions
		int getIndex(int i, int j) const { return i * SUDO_SIDELENGTH + j; }

		// Variables
		char data[SUDO_ELEMENTS_CNT];
	};
}

#endif

