//*******************************************
// SudoMatrix.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/17 10:06
// Description:
// Provide the implementation of class SudoEndGameAlgorithm.
//
// ******************************************************
#include "SudoEndGameAlgorithm.h"
#include <cstdlib>
#include <vector>

namespace Sudo
{
	SudoEndGameAlgorithm::SudoEndGameAlgorithm()
	{
	}


	SudoEndGameAlgorithm::~SudoEndGameAlgorithm()
	{
	}

	SudoMatrix SudoEndGameAlgorithm::getEndGame(
		const SudoMatrix& sudokuFinalState,
		int minEmptyEntryPerPalace,
		int totalEmptyEntryCount,
		int seed)
	{
		assert(minEmptyEntryPerPalace >= 0 && minEmptyEntryPerPalace <= SudoMatrix::SUDO_SIDELENGTH);
		assert(totalEmptyEntryCount <= SudoMatrix::SUDO_ELEMENTS_CNT);

		SudoMatrix result(sudokuFinalState);
		std::srand(seed);

		std::vector<std::pair<int, int>> posArr;
		for (int i = 0; i < SudoMatrix::SUDO_SIDELENGTH; i++)
		{
			for (int j = 0; j < SudoMatrix::SUDO_SIDELENGTH; j++)
			{
				posArr.push_back({ SudoMatrix::getIFromPalacePos(i, j), 
					SudoMatrix::getJFromPalacePos(i, j) });
			}
		}


		for (int i = SudoMatrix::SUDO_SIDELENGTH - 1; i >= 0 && totalEmptyEntryCount > 0; i--)
		{
			std::vector<int> arr = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
			for (int j = 0; j < minEmptyEntryPerPalace && totalEmptyEntryCount > 0; j++, totalEmptyEntryCount--)
			{
				int posId = std::rand() % arr.size();
				result.setNumPalace(i, arr[posId], 0);
				arr.erase(arr.begin() + posId);
				posArr.erase(posArr.begin() + (i * 9 + posId));
			}
		}
		for (; totalEmptyEntryCount > 0; totalEmptyEntryCount--)
		{
			int posId = std::rand() % posArr.size();
			result(posArr[posId].first, posArr[posId].second) = 0;
			posArr.erase(posArr.begin() + posId);
		}
		return result;
	}

	
}
