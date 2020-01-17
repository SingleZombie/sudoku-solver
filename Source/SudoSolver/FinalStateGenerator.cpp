//*******************************************************
// FinalStateGenerator.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/17 12:45
// Description:
// Provide the implementation of class FinalStateGenerator.
//
// ******************************************************

#include "FinalStateGenerator.h"
#include "SudoGenerateAlgorithm.h"
#include <vector>
#include <algorithm>

namespace Sudo
{
	FinalStateGenerator::FinalStateGenerator()
	{
	}


	FinalStateGenerator::~FinalStateGenerator()
	{
	}

	int FinalStateGenerator::generateFinalState(int count, Sudo::SudoMatrix* matrixArr, int fixFirstNumber) const
	{
		SudoGenerateAlgorithm::calTemplate();
		
		int generateCount = 0;
		std::vector<int> permutation;
		if (fixFirstNumber == 0)
		{
			permutation = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		}
		else
		{
			permutation.push_back(fixFirstNumber);
			for (int i = 1; i <= 8; i++)
			{
				if (i >= fixFirstNumber)
				{
					permutation.push_back(i + 1);
				}
				else
				{
					permutation.push_back(i);
				}
			}
		}
		do
		{
			if (fixFirstNumber != 0 && fixFirstNumber != permutation[0])
			{
				break;
			}
			         
			for (int i = 0; i < SudoGenerateAlgorithm::MAX_TEMPLATE_COUNT && generateCount < count; i++, generateCount++)
			{
				matrixArr[generateCount] = SudoGenerateAlgorithm::getSudokuFromPermutation(permutation, i);
			}
		} while (std::next_permutation(permutation.begin(), permutation.end()) && generateCount < count);

		return generateCount;
	}
}



