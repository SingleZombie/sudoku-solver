#include "pch.h"
#include "CppUnitTest.h"
#include "../SudokuSolver/EndGameGenerator.h"
#include "../SudokuSolver/FinalStateGenerator.h"
#include "../SudokuSolver/Solver.h"
#include <vector>
#include <set>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SudokuUnitTest
{
	TEST_CLASS(SolverTest)
	{
	public:
		int arrCount = 100;
		void testFun(Sudo::EndGameGenerator::Difficulty difficulty,
			int seed)
		{
			Sudo::SudoMatrix* matrixArr = new Sudo::SudoMatrix[arrCount];
			Sudo::EndGameGenerator _eG;
			Sudo::FinalStateGenerator _fG;
			Sudo::Solver _solver;
			_fG.generateFinalState(arrCount, matrixArr);
			for (int i = 0; i < arrCount; i++)
			{
				matrixArr[i] = _eG.generateEndGame(matrixArr[i], difficulty, seed);
				Assert::IsFalse(matrixArr[i].valid(), L"Validation function error");
				_solver.solve(matrixArr[i]);
				Assert::IsTrue(matrixArr[i].valid(), L"Solve failed");
			}
			delete[] matrixArr;
		}
		TEST_METHOD(TestEasy1)
		{
			testFun(Sudo::EndGameGenerator::EASY, 12343);
		}
		TEST_METHOD(TestEasy2)
		{
			testFun(Sudo::EndGameGenerator::EASY, 6757657);
		}
		TEST_METHOD(TestEasy3)
		{
			testFun(Sudo::EndGameGenerator::EASY, 7889099);
		}
		TEST_METHOD(TestMiddle1)
		{
			testFun(Sudo::EndGameGenerator::MIDDLE, 99099);
		}
		TEST_METHOD(TestMiddle2)
		{
			testFun(Sudo::EndGameGenerator::MIDDLE, 987876);
		}
		TEST_METHOD(TestMiddle3)
		{
			testFun(Sudo::EndGameGenerator::MIDDLE, 65535);
		}
		TEST_METHOD(TestHard1)
		{
			testFun(Sudo::EndGameGenerator::HARD, 987786);
		}
		TEST_METHOD(TestHard2)
		{
			testFun(Sudo::EndGameGenerator::HARD, 42563);
		}
		TEST_METHOD(TestHard3)
		{
			testFun(Sudo::EndGameGenerator::HARD, 980977);
		}
	};
}
