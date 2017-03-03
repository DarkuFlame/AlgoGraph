#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AlgoGraph/wdGraph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace wdGraphUnitTest
{
	TEST_CLASS(wdGraphUnitTest)
	{
		TEST_METHOD(TestBase)
		{
			wdGraph sample(3);
			Assert::IsTrue(sample.Base() == 0);
			
		}
	};
}