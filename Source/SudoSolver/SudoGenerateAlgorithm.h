//*******************************************************
// SudoGeneateAlgorithm.h
// Creator: ZhouYifan
// Create Date: 2020/1/16 16:40
// Description:
// Provide the definition of class SudoGenerateAlgorithm.
// SudoGenerateAlgorithm is a static class which provide the
// algorithm to generate the sudoku final state.
//
// ******************************************************

#ifndef SUDO_GENERATE_ALGORITHM_H
#define SUDO_GENERATE_ALGORITHM_H

#include "SudoMatrix.h"
#include <vector>

namespace Sudo
{
	class SudoGenerateAlgorithm
	{
	public:
		// To get the sudoku, you should generate the template first.
		static void calTemplate();
		// Search valid diffrent initial sudoku passed to solve algorithm
		static void dfs(SudoMatrix& crtMatrix, int pos, int cnt1, int cnt2, int cnt3);

		// The permutation indicates the first row of the generated sudoku. 
		static SudoMatrix getSudokuFromPermutation(std::vector<int>& permutation, int templateId);
		

		const static int MAX_TEMPLATE_COUNT;
	private:
		SudoGenerateAlgorithm();
		~SudoGenerateAlgorithm();

		static int _templateCount;
		static std::vector<SudoMatrix> _templateSudokus;
	};
}


#endif
