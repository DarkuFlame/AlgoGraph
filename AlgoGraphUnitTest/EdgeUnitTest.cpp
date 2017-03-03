#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AlgoGraph/Edge.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace EdgeUnitTest
{
	TEST_CLASS(EdgeUnitTest)
	{
	public:

		TEST_METHOD(TestSetWeight)
		{
			Edge stub(1, 2, 3);
			stub.setWeight(7);
			Assert::IsTrue(stub.weight == 7);
		}

		TEST_METHOD(TestEquals)
		{
			Edge a(1, 2, 3);
			Edge b(1, 2, 3);
			Assert::IsTrue(a == b);
			b.weight = 7;
			Assert::IsTrue(a == b);
			a.from = 2;
			Assert::IsFalse(a == b);
		}

		TEST_METHOD(Constructor)
		{
			Edge a(1, 2);
			Assert::IsTrue(a.weight == 1);
			a.weight = 2;
			Assert::IsTrue(a.weight == 2);
			a = Edge(1, 2, 3);
			Assert::IsTrue(a.weight == 3);
		}

		TEST_METHOD_INITIALIZE(Copy)
		{
			Edge a(1, 2, 3);
			Edge b(a);
			Assert::IsTrue(a == b && a.weight == b.weight);
		}
	};
}

