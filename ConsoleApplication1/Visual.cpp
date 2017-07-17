#include "stdafx.h"
#include "Visual.h"
#include "Map.h"
#include "Cell.h"
struct Visual::Impl
{
public:
	Impl(shared_ptr<Map> _map):map(_map) {}
	shared_ptr<Map> map;
	auto printCellIn(shared_ptr<Cell> cell, size_t conRow, size_t conCol)
	{
		

	}


};


Visual::Visual()
{
}


Visual::~Visual()
{
}

void Visual::printRegionIn(Region && regMap, Region && regCon)
{
	for (auto irow = 0; irow <= regMap.row2 - regMap.row1; irow++)
	{
		auto mapRow = regMap.row1 + irow;
		auto conRow = regCon.row1 + irow;
		for (auto icol = regMap.row1; icol <= regMap.row2; icol++)
		{
			auto mapCol = regMap.col1 + icol;
			auto conCol = regCon.col1 + icol;
			if (mapCol >= regMap.col2 || conCol >= regCon.col2)
			{
				break;
			}
			
			impl->printCellIn(impl->map->getCell(mapRow, mapCol), conRow, conCol);


		}

	}

}
