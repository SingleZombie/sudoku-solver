//*******************************************************
// SudoMatrix.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/1 20:54
// Description:
// Provide the implementation of class SudoMatrix.
//
// ******************************************************

#include "SudoMatrix.h"
#include <cstring>
#include <cstdio>

namespace Sudo
{
	SudoMatrix::SudoMatrix()
	{
		std::memset(_data, 0, sizeof(_data));
	}

	SudoMatrix::SudoMatrix(const SudoMatrix& matrix)
	{
		memcpy(_data, matrix._data, sizeof(_data));
	}

	SudoMatrix::SudoMatrix(char* sudoTexts)
	{
		for (int i = 0, index = 0; index < SUDO_ELEMENTS_CNT; index++, i += 2)
		{
			_data[index] = sudoTexts[i];
		}
	}

	SudoMatrix::SudoMatrix(int* sudoArrays)
	{
		for (int i = 0; i < SUDO_ELEMENTS_CNT; i++)
		{
			_data[i] = sudoArrays[i];
		}
	}

	SudoMatrix::~SudoMatrix()
	{

	}


	bool SudoMatrix::valid() const
	{
		bool isValid = true;
		int counter = 0;
		int numberApperance[SUDO_SIDELENGTH] = {};

		for (int i = 0; i < SUDO_SIDELENGTH; i++)
		{
			for (int j = 0; j < SUDO_SIDELENGTH; j++)
			{
				if (getNum(i, j) <= 0 || getNum(i, j) > 9)
				{
					isValid = false;
				}
			}
		}

		for (int i = 0; i < SUDO_SIDELENGTH && isValid; i++)
		{
			// for each rows
			for (int j = 0; j < SUDO_SIDELENGTH && isValid; j++)
			{
				if (numberApperance[getNum(i, j) - 1] != counter)
				{
					isValid = false;
				}
				else
				{
					numberApperance[getNum(i, j) - 1] = counter + 1;
				}
			}
			counter++;

			// for each cols
			for (int j = 0; j < SUDO_SIDELENGTH && isValid; j++)
			{
				if (numberApperance[getNum(j, i) - 1] != counter)
				{
					isValid = false;
				}
				else
				{
					numberApperance[getNum(j, i) - 1] = counter + 1;
				}
			}
			counter++;

			// for each palaces
			for (int j = 0; j < SUDO_SIDELENGTH && isValid; j++)
			{
				if (numberApperance[getNumPalace(i, j) - 1] != counter)
				{
					isValid = false;
				}
				else
				{
					numberApperance[getNumPalace(i, j) - 1] = counter + 1;
				}
			}
			counter++;
		}

		return isValid;
	}

	void SudoMatrix::output() const
	{
		for (int i = 0; i < SUDO_SIDELENGTH; i++)
		{
			if (i > 0)
			{
				std::putchar('\n');
			}
			for (int j = 0; j < SUDO_SIDELENGTH; j++)
			{
				if (j > 0)
				{
					std::putchar(' ');
				}
				std::printf("%c", getNum(i, j) + '0');
			}
		}
	}
}


