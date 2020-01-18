#include "pch.h"
#include "CppUnitTest.h"
#include "../SudokuSolver/FinalStateGenerator.h"
#include <vector>
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuUnitTest
{
	TEST_CLASS(FinalStateGeneatorTest)
	{
	public:
		int getSudoNum(const Sudo::SudoMatrix& matrix, int row)
		{
			int num = 0;
			for (int j = 0; j < 9; j++)
			{
				num = num * 10 + matrix(row, j);
			}
			return num;
		}
		std::vector<int> getSudoArr(const Sudo::SudoMatrix& matrix)
		{
			std::vector<int> res;
			for (int i = 0; i < 9; i++)
			{
				res.push_back(getSudoNum(matrix, i));
			}
			return res;
		}
		bool cmp(const std::vector<int>& arr, const std::vector<int>& arr2)
		{
			for (int i = 0; i < arr.size(); i++)
			{
				if (arr[i] != arr2[i])
				{
					return arr[i] < arr2[i];
				}
			}
			return false;
		}
		TEST_METHOD(FinalStateGeneratorTest1)
		{
			int cnt = 1000;
			Sudo::FinalStateGenerator _finalStateGenerator;
			Sudo::SudoMatrix* sudoArr = new Sudo::SudoMatrix[cnt];
			_finalStateGenerator.generateFinalState(cnt, sudoArr, 4);
			for (int i = 0; i < cnt; i++)
			{
				std::wstringstream ss;
				ss << L"First number not Equal: " << i;
				Assert::AreEqual(4, (int)sudoArr[i](0, 0), ss.str().c_str());
				Assert::IsTrue(sudoArr[i].valid());
				for (int j = 0; j < i; j++)
				{
					Assert::IsFalse(sudoArr[i] == sudoArr[j], L"Find same sudoku!");
				}
			}

			delete[] sudoArr;
		}
		TEST_METHOD(FinalStateGeneratorTest2)
		{
			int cnt = 1000000;
			Sudo::FinalStateGenerator _finalStateGenerator;
			Sudo::SudoMatrix* sudoArr = new Sudo::SudoMatrix[cnt];
			_finalStateGenerator.generateFinalState(cnt, sudoArr, 4);

			std::set<std::vector<int>> arrSet;
			for (int i = 0; i < cnt; i++)
			{
				std::wstringstream ss;
				ss << L"First number not Equal: " << i;
				Assert::AreEqual(4, (int)sudoArr[i](0, 0), ss.str().c_str());
				Assert::IsTrue(sudoArr[i].valid());
				std::vector<int> numArr = getSudoArr(sudoArr[i]);
				Assert::IsFalse(arrSet.count(numArr), L"Find same sudoku!");
				arrSet.insert(numArr);
			}

			delete[] sudoArr;
		}
	};
}
