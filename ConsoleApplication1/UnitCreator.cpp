#include "stdafx.h"

#include "unit.h"
#include "UnitCreator.h"
#include "Value.h"
#include "RandomGame.h"
#include "ItemCreater.h"
#include "Bag.h"

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
		auto & hp = unit->getParam(L"hp");
		hp = 10;

		function<void(double val)> a = [unit](double val) {if (val <= 0) unit->destroy(); };

		hp.setWatcher(a);

		unit->getParam(L"attack") = 10;

		auto bag = unit->getBag();

		auto random = 10;
		for (auto i = 0; i < random; i++) {
			bag->push_back(ItemCreater::createItem(L"some item"));
		}


	}
	catch (const std::out_of_range& oor)
	{
		//std::cerr << "Out of Range error: " << oor.what() << '\n';
		throw oor;  //TODO Visual::error("вышел за границы")
	}

	return unit;
}
