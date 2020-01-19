//*******************************************************
// CmdInteraction.h
// Creator: ZhouYifan
// Create Date: 2020/1/17 14:09
// Description:
// Provide the implementation of class CmdInteraction.
//
// ******************************************************

#include "CmdInteraction.h"

namespace Sudo
{
	CmdInteraction::CmdInteraction()
	{
	}


	CmdInteraction::~CmdInteraction()
	{
	}

	bool CmdInteraction::inputCmd(int argc, char* argv[])
	{
		if (argc > 3)
		{
			puts("ERROR: Too many arguments!");
			return false;
		}
		if (argc < 3)
		{
			puts("ERROR: Too few arguments!");
			return false;
		}
		return processCmd(argv[1], argv + 2);
	}

	bool CmdInteraction::processCmd(char* cmdText, char* argPtr[])
	{
		bool cmdValid = false;
		bool argValid = false;
		if (cmdText[0] == '-')
		{
			if (cmdText[1] == 'c')
			{
				cmdValid = true;
				argValid = generateSudoku(argPtr);
			}
			else if (cmdText[1] == 's')
			{
				cmdValid = true;
				argValid = solveSudoku(argPtr);
			}
		}
		if (!cmdValid)
		{
			puts("ERROR: Command doesn't exist!");
		}
		else if (!argValid)
		{
			puts("ERROR: Command execute failed, maybe argument error!");
		}
		return cmdValid && argValid;
	}
	bool CmdInteraction::generateSudoku(char* arg[])
	{
		int cnt;
		if (sscanf_s(arg[0], "%d", &cnt) != 1)
		{
			puts("ERROR: Generate sudoku argument error");
			return false;
		}
		if (!(cnt >= 1 && cnt <= 1000000))
		{
			puts("ERROR: The count is not in range[1, 1000000].");
			return false;
		}
		SudoMatrix* matrices = new SudoMatrix[cnt];
		if (_finalStateGenerator.generateFinalState(cnt, matrices, 4) != cnt)
		{
			return false;
		}
		FILE* fp = NULL;
		if (fopen_s(&fp, "sudoku.txt", "w") != 0)
		{
			puts("ERROR: Cannot write to sudoku.txt.");
			return false;
		}
		if (SudoMatrixIO::writeMatrices(fp, matrices, cnt) != cnt)
		{
			puts("ERROR: Write Matrices to file error.");
			return false;
		}
		delete[] matrices;
		if (fp)
			fclose(fp);
		return true;
	}
	bool CmdInteraction::solveSudoku(char* arg[])
	{
		char fileName[256] = {};
		if (sscanf_s(arg[0], "%s", fileName, 256) != 1)
		{
			puts("ERROR: Solve sudoku arguments read error.");
			return false;
		}
		SudoMatrix tmpMatrix;
		FILE* fpIn;
		if (fopen_s(&fpIn, fileName, "r") != 0 || fpIn == NULL)
		{
			printf("ERROR: Cannot read %s\n", fileName);
			return false;
		}

		FILE* fpOut = NULL;
		if (fopen_s(&fpOut, "sudoku.txt", "w") != 0 || fpOut == NULL)
		{
			puts("ERROR: Cannot write to sudoku.txt.");
			return false;
		}
		while (true)
		{
			int readResult = SudoMatrixIO::readMatrix(fpIn, tmpMatrix);
			if (readResult == -2)
			{
				puts("ERROR: File format error and can't build matrix");
				return false;
			}

			_solver.solve(tmpMatrix);
			if (SudoMatrixIO::writeMatrices(fpOut, &tmpMatrix, 1) != 1)
			{
				puts("ERROR: Write Matrix to file error.");
				return false;
			}

			if (readResult == EOF)
			{
				break;
			}

			fputc('\n', fpOut);
			fputc('\n', fpOut);
		}
		if (fpIn)
			fclose(fpIn);
		if (fpOut)
			fclose(fpOut);
		return true;
	}
}


