#include "pch.h"
#include "CppUnitTest.h"
#include "../11.4/11.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(CountWordsInLine("Hello world!"), 2);
			Assert::AreEqual(CountWordsInLine("    "), 0); 
			Assert::AreEqual(CountWordsInLine("One, two, three."), 3); 
			Assert::AreEqual(CountWordsInLine("This is a test."), 4); 
		}
	};
}
