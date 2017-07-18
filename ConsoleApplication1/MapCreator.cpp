#include "stdafx.h"
#include "MapCreator.h"

#include "Map.h"
#include "Cell.h"
#include "unit.h"

struct MapCreator::Impl {
	
	size_t rowCount = 12;
	size_t colCount = 20;

	wstring mapstring = 
		L"@                   "
		L"  @                 "
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

MapCreator::MapCreator():impl(make_unique<Impl>())
{
}


MapCreator::~MapCreator()
{
}

auto MapCreator::createMap()-> shared_ptr<Map>
{
	auto map = make_shared<Map>(impl->rowCount, impl->colCount);

	for (size_t row = 0; row < impl->rowCount; row++)
		for (size_t col = 0; col < impl->colCount; col++) {
			wchar_t ch = impl->mapstring[row * impl->colCount + col];
			if (ch != ' ')
			{
				
				//shared_ptr<ISpaceObject> sp(new Unit('@'));
				//shared_ptr<Unit> sp(new Unit(ch));
				//shared_ptr<ISpaceObject> sp2(sp);


				map->getCell(row, col)->setSpaceObject(make_shared<Unit>(ch));
			}
		}
	return map;
}
