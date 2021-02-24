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

			int  arr[3] = {3,6,9 };
			
			SearchMin(arr, 3);

			Assert::AreEqual(arr[0], 3);
		}
	};
}
