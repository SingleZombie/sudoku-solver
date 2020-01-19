//*********************************************
// SudoGeneateAlgorithm.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/16 16:41
// Description:
// Provide the implementation of class SudoGenerateAlgorithm.
//
// ******************************************************

#include "SudoGenerateAlgorithm.h"
#include "SudoSolveAlgorithm.h"
#include "SudoMatrixIO.h"
namespace Sudo
{
	const int SudoGenerateAlgorithm::MAX_TEMPLATE_COUNT = 56;
	int  SudoGenerateAlgorithm::_templateCount = 0;
	std::vector<SudoMatrix>  SudoGenerateAlgorithm::_templateSudokus;

	SudoGenerateAlgorithm::SudoGenerateAlgorithm()
	{

	}

	SudoGenerateAlgorithm::~SudoGenerateAlgorithm()
	{

	}

	void SudoGenerateAlgorithm::calTemplate()
	{
		if (_templateCount != 0)
		{
			return;
		}
		_templateCount = MAX_TEMPLATE_COUNT;

		/* Template Calculation Code

		// The matrix that is used to generate the first and second rows 
		SudoMatrix originMatrix;

		// Set the first row to 1~9
		for (int i = 0; i < 9; i++)
		{
			originMatrix(0, i) = i + 1;
		}

		dfs(originMatrix, 0, 0, 0, 0);*/


		FILE* fp;
		fopen_s(&fp, "templates.txt", "r");
		for (int i = 0; i < _templateCount; i++)
		{
			SudoMatrix newMatrix;
			SudoMatrixIO::readMatrix(fp, newMatrix);
			_templateSudokus.push_back(newMatrix);
		}
		
		if (fp)
			fclose(fp);
	}

	void SudoGenerateAlgorithm::dfs(SudoMatrix& crtMatrix, int pos, int cnt1, int cnt2, int cnt3)
	{
		if (_templateSudokus.size() == _templateCount)
		{
			return;
		}
		if (cnt1 == 3 && cnt2 == 3 && cnt3 == 3)
		{
			SudoMatrix tmpMatrix(crtMatrix);
			SudoSolveAlgorithm::solve(tmpMatrix);
			
			
			_templateSudokus.push_back(tmpMatrix);
			return;
		}

		if (pos < 3)
		{
			if (cnt2 < 3)
			{
				crtMatrix(1, pos) = crtMatrix(0, 3 + cnt2);
				dfs(crtMatrix, pos + 1, cnt1, cnt2 + 1, cnt3);
			}
			if (cnt3 < 3)
			{
				crtMatrix(1, pos) = crtMatrix(0, 6 + cnt3);
				dfs(crtMatrix, pos + 1, cnt1, cnt2, cnt3 + 1);
			}
		}
		else if (pos < 6)
		{
			if (cnt1 < 3)
			{
				crtMatrix(1, pos) = crtMatrix(0, cnt1);
				dfs(crtMatrix, pos + 1, cnt1 + 1, cnt2, cnt3);
			}
			if (cnt3 < 3)
			{
				crtMatrix(1, pos) = crtMatrix(0, 6 + cnt3);
				dfs(crtMatrix, pos + 1, cnt1, cnt2, cnt3 + 1);
			}
		}
		else
		{
			if (cnt1 < 3)
			{
				crtMatrix(1, pos) = crtMatrix(0, cnt1);
				dfs(crtMatrix, pos + 1, cnt1 + 1, cnt2, cnt3);
			}
			if (cnt2 < 3)
			{
				crtMatrix(1, pos) = crtMatrix(0, 3 + cnt2);
				dfs(crtMatrix, pos + 1, cnt1, cnt2 + 1, cnt3);
			}
		}
	
	}

	SudoMatrix SudoGenerateAlgorithm::getSudokuFromPermutation(std::vector<int>& permutation, int templateId)
	{
		assert(permutation.size() == 9);
		assert(templateId >= 0 && templateId < _templateCount);

		SudoMatrix result = _templateSudokus[templateId];
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int newIndex = result(i, j) - 1;
				result(i, j) = permutation[newIndex];
			}
		}
		return result;
	}
}

