#include "stdafx.h"

#include "unit.h"
#include "UnitCreator.h"
#include "Value.h"

UnitCreator::UnitCreator()
{
}


UnitCreator::~UnitCreator()
{
}

shared_ptr<Unit> UnitCreator::createUnit(wchar_t ch)
{
	auto unit = make_shared<Unit>(ch);
	unit->initParams();
	
	try
	{
		unit->getParam(L"hp") = 10;
		unit->getParam(L"attack") = 10;
	}
	catch (const std::out_of_range& oor)
	{
		//std::cerr << "Out of Range error: " << oor.what() << '\n';
		throw oor;  //TODO Visual::error("вышел за границы")
	}

	return unit;
}
