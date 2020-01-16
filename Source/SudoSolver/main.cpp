//*******************************************************
// Main.cpp
// Creator: ZhouYifan
// Create Date: 2020/1/1 20:38
// Description:
// The entry of the program.
//
// ******************************************************

#include "main.h"
int main(int argc, char* argv[])
{
	Sudo::SudoGenerateAlgorithm::calTemplate();
	std::vector<int> arr;
	for (int i = 0; i < 9; i++)
	{
		arr.push_back(i + 1);
	}
	for (int i = 0; i < 56; i++)
	{
		auto tmp = Sudo::SudoGenerateAlgorithm::getSudokuFromPermutation(arr, i);
		tmp.output();
		printf("\nvalid = %s\n", tmp.valid() ? "yes" : "no");
	}
	
	system("pause");
	return 0;
}

