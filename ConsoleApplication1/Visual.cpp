#include "stdafx.h"
#include <array>


#include "Visual.h"
#include "Map.h"
#include "Cell.h"
#include "unit.h"
#include "Value.h"

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
	unique_ptr<Unit, function<void(Unit*)>> hero;
	const size_t sizeRow = 10;
	const size_t sizeCol = 10;

public:
	array<HANDLE, 2> handles;
	array<HANDLE, 2> ::iterator itHandle;


	Impl() :hero(nullptr, [](Unit* u) {})
	{
		

	}

	void setMap(shared_ptr<Map> _map, Unit* _hero)
	{
		map = _map;
		hero.reset(_hero);
		for (auto & ihandle : handles)
			ihandle = createBuffer();

		itHandle = handles.begin();
		setActiveBuffer(*itHandle);
		itHandle++;
	}

	

	auto printCellIn(shared_ptr<Cell> cell, short conRow, short conCol)
	{
		putChar(*itHandle, COORD{conCol, conRow}, (cell)?cell->getChar():' ', Color::White, Color::Black);
	}

};


Visual::Visual():impl(make_unique<Impl>())
{
}


Visual::~Visual()
{
}

void Visual::setMap(shared_ptr<Map> map, Unit* hero)
{
	impl->setMap(map, hero);
}

void Visual::printRegionIn(MapReg && regMap, Region && regCon)
{
	cleanRegion(Region(regCon));
	for (size_t irow = 0; irow <= regMap.bottomRight.row - regMap.topLeft.row; irow++) {
		auto mapRow = regMap.topLeft.row + irow;
		auto conRow = regCon.row1 + irow;
		for (size_t icol = 0; icol <= regMap.bottomRight.col - regMap.topLeft.col; icol++) {
			size_t mapCol = regMap.topLeft.col + icol;
			size_t conCol = regCon.col1 + icol;
			if (mapCol >= regMap.bottomRight.col || conCol >= (size_t)regCon.col2)
				break;

			impl->printCellIn(impl->map->getCell(mapRow, mapCol, false), (short)conRow, (short)conCol);
		}
	}

	impl->changeBuffer();	
}

void Visual::cleanRegion(Region && regConsole)
{
	clearRect(*impl->itHandle, regConsole, ' ');
}

void Visual::printMap()
{

	printParams();

	MapReg regmap = getRegMapForPrint();
	printBorder(Region{ 0,0, 12, 12 });
	printRegionIn(move(regmap), Region{ 1,1, 11, 11 });
}

bool Visual::isInRegion(const Coords &coords)
{
	auto sz = impl->map->getSize();
	return (coords.row >= 0 && coords.col < sz.row) && (coords.col >= 0 && coords.col < sz.col);
}

MapReg Visual::getRegMapForPrint()
{
	MapReg regmap;
	auto coord = impl->hero->getCoord();
	auto mapSize = impl->map->getSize();
	
	auto cr = coord.row - impl->sizeRow / 2;

	auto func = [](size_t cr, size_t &wher, size_t comp,  size_t what) { wher = (cr > 0 && cr < comp) ? cr : what; };

	func(coord.row - impl->sizeRow / 2, regmap.topLeft.row, mapSize.row, 0);
	func(coord.col - impl->sizeCol / 2, regmap.topLeft.col, mapSize.col, 0);
	func(coord.row + impl->sizeRow / 2, regmap.bottomRight.row, mapSize.row, mapSize.row);
	func(coord.col + impl->sizeCol / 2, regmap.bottomRight.col, mapSize.col, mapSize.col);
	
	if (regmap.topLeft.row == 0)
		regmap.bottomRight.row = min(mapSize.row -1, impl->sizeRow -1);


	if (regmap.topLeft.col == 0)
		regmap.bottomRight.col = min(mapSize.col-1, impl->sizeCol -1);


	if (regmap.bottomRight.row == mapSize.row - 1)
		regmap.topLeft.row = min(0, regmap.bottomRight.row - impl->sizeRow+1);


	if (regmap.bottomRight.col == mapSize.row - 1)
		regmap.topLeft.col = min(0, regmap.bottomRight.col - impl->sizeCol + 1);



	return regmap;
}

void Visual::printBorder(const Region &rg) const
{
	printRegion(*impl->itHandle, rg, Color::White, Color::Black);
}

void Visual::printParams()
{
	static const array<const wstring, 2> paramKeys = {L"hp", L"attack"};
	short i = 0;
	for (auto& key : paramKeys)
	{
		putChar(*impl->itHandle, COORD{ 20, 5 + i ++ }, key + (L":") + std::to_wstring(static_cast<double>(impl->hero->getParam(key))), Color::White, Color::Black);


	}
	

}
