// Unit-тест до завдання 6.1 (рекурсивний спосіб). Варіант 20
// Критерій: всі від'ємні, крім кратних 3.
#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr6.1_rec/Pr6.1_rec.cpp"      // шлях і назву файлу змініть на свої

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61_rec
{
	TEST_CLASS(UnitTest61_rec)
	{
	public:

		TEST_METHOD(TestCount)
		{
			// підходять: -8, -17, -1 (а -6 і -9 кратні 3, 0 і додатні - не від'ємні)
			int x[8] = { -8, -6, 5, 0, -17, 9, -1, -9 };
			int t = Count(x, 8, 0);
			Assert::AreEqual(3, t);
		}

		TEST_METHOD(TestSum)
		{
			int x[8] = { -8, -6, 5, 0, -17, 9, -1, -9 };
			int t = Sum(x, 8, 0);
			Assert::AreEqual(-26, t);
		}

		TEST_METHOD(TestCountNone)
		{
			// немає жодного елемента, що задовольняє критерію
			int x[5] = { 1, 2, 3, 0, 7 };
			Assert::AreEqual(0, Count(x, 5, 0));
			Assert::AreEqual(0, Sum(x, 5, 0));
		}

		TEST_METHOD(TestZeroing)
		{
			int x[8] = { -8, -6, 5, 0, -17, 9, -1, -9 };
			int e[8] = { 0, -6, 5, 0, 0, 9, 0, -9 };
			Zeroing(x, 8, 0);
			for (int i = 0; i < 8; i++)
				Assert::AreEqual(e[i], x[i]);
		}
	};
}