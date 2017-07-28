#include "stdafx.h"
#include "MapCreator.h"
#include "UnitCreator.h"

#include "Map.h"
#include "Cell.h"
#include "unit.h"
#include "SimpleMover.h"
#include "Value.h"
#include "AI.h"

struct MapCreator::Impl {

	crd rowCount = 12;
	crd colCount = 20;

	wstring mapstring =
		L"@                   "
		L"  F                 "
		L"                    "
		L"                    "
		L"   q        $       "
		L"                    "
		L"               $    "
		L"      q             "
		L"                    "
		L"          q         "
		L"                    "
		L"      q             "
		;


};

MapCreator::MapCreator() :impl(make_unique<Impl>())
{
}


MapCreator::~MapCreator()
{
}

auto MapCreator::createMap(shared_ptr<AI> ai)-> shared_ptr<Map>
{
	auto map = make_shared<Map>(impl->rowCount, impl->colCount);

	for (crd row = 0; row < impl->rowCount; row++)
		for (crd col = 0; col < impl->colCount; col++) {
			wchar_t ch = impl->mapstring[row * impl->colCount + col];

			auto unit = UnitCreator::createUnit(ch);

			unit->setMover(new SimpleMover(map, map->getCell(row, col, true), Coords{ row, col }, unit));

			if (ch == '@') {
				map->getCell(row, col, true)->setSpaceObject(unit);
			}
			else if (ch != ' ') {
					
				ai->addEnemy(unit);
				map->getCell(row, col, true)->setSpaceObject(unit);
			}

		}
	return map;
}
