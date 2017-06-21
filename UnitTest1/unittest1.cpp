#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Cell.h"
#include "Unit.h"

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Cell cell;

			std::unique_ptr<ISpaceObject> ispace = std::make_unique<ISpaceObject>();
			cell.setSpaceObject(move(ispace));
			// TODO: Разместите здесь код своего теста
			Assert::IsNull(ispace.get());
		}

	};
}