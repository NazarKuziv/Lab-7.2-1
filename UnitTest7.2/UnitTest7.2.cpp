#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 7.2-1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72
{
	TEST_CLASS(UnitTest72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			int a[3][3] = { { 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 } };
			int* pa[3] = { a[0], a[1], a[2] };

			int* arr = new int[3];

			SearchMin(pa, 3, 3, arr);

			Assert::AreEqual(arr[0], 1);
		}
	};
}
