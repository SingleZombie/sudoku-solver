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

#include <cassert>

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
			return _data[getIndex(i, j)];
		}

		void setNum(int i, int j, char num)
		{
			_data[getIndex(i, j)] = num;
		}

		char getNumPalace(int i, int j) const
		{
			return _data[getIndex((i / 3) * 3 + (j / 3) , (i % 3) * 3 + (j % 3))];
		}

		void setNumPalace(int i, int j, char num)
		{
			_data[getIndex((i / 3) * 3 + (j / 3), (i % 3) * 3 + (j % 3))] = num;
		}

		static int getPalaceId(int i, int j)
		{
			return i / 3 * 3 + j / 3;
		}

		static int getIdInPalace(int i, int j)
		{
			return i % 3 * 3 + j % 3;
		}

		char operator()(int i, int j) const
		{
			return _data[getIndex(i, j)];
		}

		char& operator()(int i, int j)
		{
			return _data[getIndex(i, j)];
		}

		// Variables

		// Constants
		static const unsigned SUDO_SIDELENGTH = 9;
		static const unsigned SUDO_ELEMENTS_CNT = SUDO_SIDELENGTH * SUDO_SIDELENGTH;
	private:

		// inline functions
		int getIndex(int i, int j) const 
		{
			if (i < 0 || i >= SUDO_SIDELENGTH || j < 0 || j >= SUDO_SIDELENGTH)
			{
				throw "Index not valid when access sudoku matrix";
			}
			return i * SUDO_SIDELENGTH + j;
		}

		// Variables
		char _data[SUDO_ELEMENTS_CNT];
	};
}

#endif

