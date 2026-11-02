#include "pch.h"
#include "CppUnitTest.h"
#include "../ЛР 7.2 іт/ЛР 7.2 іт.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test72
{
	TEST_CLASS(test72)
	{
	public:

		int** MakeMatrix(const int rows, const int cols, const int* data)
		{
			int** a = new int* [rows];
			for (int i = 0; i < rows; i++)
			{
				a[i] = new int[cols];
				for (int j = 0; j < cols; j++)
					a[i][j] = data[i * cols + j];
			}
			return a;
		}

		void DeleteMatrix(int** a, const int rows)
		{
			for (int i = 0; i < rows; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSumMinEvenCols)
		{
			int data[12] = { 5, 9, 2, 8,   7, 1, 6, 3,   4, 6, 9, 1 };
			int** a = MakeMatrix(3, 4, data);
			int result = SumMinEvenCols(a, 3, 4);
			Assert::AreEqual(2, result);
			DeleteMatrix(a, 3);
		}

		TEST_METHOD(TestSumMinEvenCols_2x2)
		{
			int data[4] = { 3, 8,   5, 4 };
			int** a = MakeMatrix(2, 2, data);
			int result = SumMinEvenCols(a, 2, 2);
			Assert::AreEqual(4, result);
			DeleteMatrix(a, 2);
		}

		TEST_METHOD(TestSumMinEvenCols_OneColumn)
		{
			int data[3] = { 1, 2, 3 };
			int** a = MakeMatrix(3, 1, data);
			int result = SumMinEvenCols(a, 3, 1);
			Assert::AreEqual(0, result);
			DeleteMatrix(a, 3);
		}

		TEST_METHOD(TestCreate_Range)
		{
			int data[12] = { 0 };
			int** a = MakeMatrix(3, 4, data);
			Create(a, 3, 4, 7, 65);
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 4; j++)
				{
					Assert::IsTrue(a[i][j] >= 7);
					Assert::IsTrue(a[i][j] <= 65);
				}
			DeleteMatrix(a, 3);
		}
	};
}