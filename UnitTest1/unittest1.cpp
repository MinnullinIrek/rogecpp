#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Cell.h"
#include "unit.h"

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Cell cell;
			
			
			std::shared_ptr<ISpaceObject> ispace = std::make_shared<Unit>(' ');
			ISpaceObject *sp1 = ispace.get();

			cell.setSpaceObject(ispace);
			ISpaceObject *sp2 = cell.getSpaceObject().get();
			// TODO: Разместите здесь код своего теста
			Assert::IsTrue(sp1 == sp2);
		}

	};
}