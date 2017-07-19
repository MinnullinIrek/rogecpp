#include "stdafx.h"

#include <array>


#include "Visual.h"
#include "Map.h"
#include "Cell.h"

struct Visual::Impl
{
	void changeBuffer()
	{
		setActiveBuffer(*itHandle);
		if (itHandle == handles.begin())
			++itHandle;
		else
			--itHandle;
	}
	shared_ptr<Map> map;
public:
	array<HANDLE, 2> handles;
	array<HANDLE, 2> ::iterator itHandle;

	Impl()
	{
		

	}

	void setMap(shared_ptr<Map> _map)
	{
		map = _map;
		for (auto & ihandle : handles)
			ihandle = createBuffer();

		itHandle = handles.begin();
		setActiveBuffer(*itHandle);
		itHandle++;
	}

	

	auto printCellIn(shared_ptr<Cell> cell, short conRow, short conCol)
	{
		putChar(*itHandle, COORD{conCol, conRow}, cell->getChar(), Color::White, Color::Black);
	}

};


Visual::Visual():impl(make_unique<Impl>())
{
}


Visual::~Visual()
{
}

void Visual::setMap(shared_ptr<Map> map)
{
	impl->setMap(map);
}

void Visual::printRegionIn(Region && regMap, Region && regCon)
{
	cleanRegion(Region(regCon));
	for (auto irow = 0; irow <= regMap.row2 - regMap.row1; irow++) {
		auto mapRow = regMap.row1 + irow;
		auto conRow = regCon.row1 + irow;
		for (auto icol = regMap.row1; icol <= regMap.row2; icol++) {
			auto mapCol = regMap.col1 + icol;
			auto conCol = regCon.col1 + icol;
			if (mapCol >= regMap.col2 || conCol >= regCon.col2)
				break;

			impl->printCellIn(impl->map->getCell(mapRow, mapCol), conRow, conCol);
		}
	}

	impl->changeBuffer();	
}

void Visual::cleanRegion(Region && regConsole)
{
	clearRect(*impl->itHandle, regConsole, ' ');
}
