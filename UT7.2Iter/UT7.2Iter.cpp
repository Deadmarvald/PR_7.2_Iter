#include "pch.h"
#include "CppUnitTest.h"
#include "../PR7.2Iter/Lab_07_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT72Iter
{
	TEST_CLASS(UT72Iter)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int t;

			int** a = new int* [2];
			for (int i = 0; i < 2; i++)
				a[i] = new int[2];

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					a[i][j] = 0;
				}
			}
			t = SearchMin(a, 2, 0);

			Assert::AreEqual(t, 0);
		}
	};
}