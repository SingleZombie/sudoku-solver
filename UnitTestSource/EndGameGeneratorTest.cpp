#include "pch.h"
#include "CppUnitTest.h"
#include "../SudokuSolver/EndGameGenerator.h"
#include "../SudokuSolver/FinalStateGenerator.h"
#include <vector>
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuUnitTest
{
	TEST_CLASS(EndGameGeneratorTest)
	{
	public:
		int arrCount = 100;
		void testFun(Sudo::EndGameGenerator::Difficulty difficulty,
			int palaceMinZero,
			int totalZero,
			int seed)
		{
			Sudo::SudoMatrix* matrixArr = new Sudo::SudoMatrix[arrCount];
			Sudo::EndGameGenerator _eG;
			Sudo::FinalStateGenerator _fG;
			_fG.generateFinalState(arrCount, matrixArr);
			for (int i = 0; i < arrCount; i++)
			{
				matrixArr[i] = _eG.generateEndGame(matrixArr[i], difficulty, seed);
				int zeroCnt = 0;
				for (int ii = 0; ii < 9; ii++)
				{
					int palaceZero = 0;
					for (int jj = 0; jj < 9; jj++)
					{
						if (matrixArr[i].getNumPalace(ii, jj) == 0)
						{
							zeroCnt++;
							palaceZero++;
						}
					}
					Assert::IsTrue(palaceZero >= palaceMinZero, L"Palace empty entry count is not enough");
				}
				Assert::AreEqual(zeroCnt, totalZero, L"Total empty entry count is not enough");
			}
			delete[] matrixArr;
		}
		TEST_METHOD(TestEasy1)
		{
			testFun(Sudo::EndGameGenerator::EASY, 2, 20, 12343);
		}
		TEST_METHOD(TestEasy2)
		{
			testFun(Sudo::EndGameGenerator::EASY, 2, 20, 6757657);
		}
		TEST_METHOD(TestEasy3)
		{
			testFun(Sudo::EndGameGenerator::EASY, 2, 20, 7889099);
		}
		TEST_METHOD(TestMiddle1)
		{
			testFun(Sudo::EndGameGenerator::MIDDLE, 2, 40, 99099);
		}
		TEST_METHOD(TestMiddle2)
		{
			testFun(Sudo::EndGameGenerator::MIDDLE, 2, 40, 987876);
		}
		TEST_METHOD(TestMiddle3)
		{
			testFun(Sudo::EndGameGenerator::MIDDLE, 2, 40, 65535);
		}
		TEST_METHOD(TestHard1)
		{
			testFun(Sudo::EndGameGenerator::HARD, 3, 60, 987786);
		}
		TEST_METHOD(TestHard2)
		{
			testFun(Sudo::EndGameGenerator::HARD, 3, 60, 42563);
		}
		TEST_METHOD(TestHard3)
		{
			testFun(Sudo::EndGameGenerator::HARD, 3, 60, 980977);
		}
	};
}
