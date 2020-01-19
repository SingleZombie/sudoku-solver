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
		const static int CHAR_CNT = 162;
		static char buf[CHAR_CNT];
		fread(buf, sizeof(char), CHAR_CNT, fp);
		matrix = SudoMatrix(buf);
		return fgetc(fp) == EOF ? EOF : 0;
	}

	int SudoMatrixIO::writeMatrices(std::FILE* fp, const SudoMatrix* matricesArray, int count)
	{
		const static int MAX_MATRIX_CNT = 100;
		const static int BUF_SIZE = 18 * 9 * MAX_MATRIX_CNT + 5;
		static char buf[BUF_SIZE];
		int bufIndex = 0;
		int successfulCount = 0;
		for (int mi = 0; mi < count; mi++)
		{
			for (int i = 0; i < SudoMatrix::SUDO_SIDELENGTH; i++)
			{
				for (int j = 0; j < SudoMatrix::SUDO_SIDELENGTH; j++)
				{
					char ch = matricesArray[mi](i, j) + '0';
					buf[bufIndex++] = ch;
					if (!(mi == count - 1 && i == 8 && j == 8))
					{
						buf[bufIndex++] = j == SudoMatrix::SUDO_SIDELENGTH - 1 ? '\n' : ' ';
					}
				}
			}
			successfulCount++;
			if (mi + 1 < count)
			{
				buf[bufIndex++] = '\n';
			}
			if (mi % MAX_MATRIX_CNT == MAX_MATRIX_CNT - 1)
			{
				fwrite(buf, sizeof(char), bufIndex, fp);
				bufIndex = 0;
			}
		}
		fwrite(buf, sizeof(char), bufIndex, fp);
		
		return successfulCount;
	}
}


