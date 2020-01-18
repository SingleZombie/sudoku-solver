//*******************************************************
// SudoMatrixIO.h
// Creator: ZhouYifan
// Create Date: 2020/1/17 14:15
// Description:
// Provide the implementation of class SudoMatrixIO.
//
// ******************************************************

#include "SudoMatrixIO.h"

namespace Sudo
{
	SudoMatrixIO::SudoMatrixIO()
	{
	}

	SudoMatrixIO::~SudoMatrixIO()
	{
	}

	int SudoMatrixIO::readMatrix(std::FILE* fp, SudoMatrix& matrix)
	{
		int num;
		for (int i = 0; i < SudoMatrix::SUDO_SIDELENGTH; i++)
		{
			for (int j = 0; j < SudoMatrix::SUDO_SIDELENGTH; j++)
			{
				if (fscanf_s(fp, "%d", &num) != 1)
				{
					return -2;
				}
				matrix(i, j) = num;
			}
		}
		return fgetc(fp) == EOF ? EOF : 0;
	}

	int SudoMatrixIO::writeMatrices(std::FILE* fp, const SudoMatrix* matricesArray, int count)
	{
		int successfulCount = 0;
		for (int mi = 0; mi < count; mi++)
		{
			for (int i = 0; i < SudoMatrix::SUDO_SIDELENGTH; i++)
			{
				for (int j = 0; j < SudoMatrix::SUDO_SIDELENGTH; j++)
				{
					char ch = matricesArray[mi](i, j) + '0';
					fputc(ch, fp);
					if (!(mi == count - 1 && i == 8 && j == 8))
					{
						fputc(j == SudoMatrix::SUDO_SIDELENGTH - 1 ? '\n' : ' ', fp);
					}
				}
			}
			successfulCount++;
			if (mi + 1 < count)
			{
				fputc('\n', fp);
			}
		}
		
		return successfulCount;
	}
}


