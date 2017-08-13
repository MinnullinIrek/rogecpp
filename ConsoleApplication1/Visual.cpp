#include "stdafx.h"
#include <array>
#include <unordered_map>

#include "Visual.h"
#include "Map.h"
#include "Cell.h"
#include "unit.h"
#include "Value.h"
#include "Bag.h"
#include "IItem.h"


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
	const crd sizeRow = 10;
	const crd sizeCol = 10;

	VisualState state = VisualState::map;

	unordered_map<wstring, int> currents;

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

	void showBag(shared_ptr<Bag> bag, Region && regConsole, int current)
	{
		cleanRegion(regConsole);

		short y = 0;

		bag->forEach([current, &y, this, &regConsole](shared_ptr<Item> item) 
		{
			putChar(*itHandle, COORD{ regConsole.col1,  regConsole.row1 + y }, wstring(y==current ? L"[*]" : L"[ ]") + item->getName(INameble::Type::name), Color::White, Color::Black); 
			y++;
			return BagItemDo::next;
		});
	}

	auto printCellIn(shared_ptr<Cell> cell, short conRow, short conCol)
	{
		putChar(*itHandle, COORD{ conCol, conRow }, (cell) ? cell->getChar() : ' ', Color::White, Color::Black);
	}

	void cleanRegion(Region && regConsole)
	{
		clearRect(*itHandle, regConsole, ' ');
	}

	void cleanRegion(const Region & regConsole)
	{
		clearRect(*itHandle, regConsole, ' ');
	}

	void showHeroBag()
	{
		showBag(hero->getBag(), { 0, 0, 50, 50 }, currents[L"currentBagItem"]);
	}

	void printMap()
	{
		printParams();

		MapReg regmap = getRegMapForPrint();
		printBorder(Region{ 0,0, 12, 12 });
		printRegionIn(move(regmap), Region{ 1,1, 11, 11 });
	}

	void printParams()
	{
		static const array<const wstring, 2> paramKeys = { L"hp", L"attack" };
		short i = 0;
		for (auto& key : paramKeys) {
			putChar(*itHandle, COORD{ 20, 5 + i++ }, key + (L":") + std::to_wstring(static_cast<double>(hero->getParam(key))), Color::White, Color::Black);
		}
	}

	MapReg getRegMapForPrint()
	{
		MapReg regmap;
		auto coord = hero->getCoord();
		auto mapSize = map->getSize();

		auto cr = coord.row - sizeRow / 2;

		auto func = [](size_t cr, size_t &wher, size_t comp, size_t what) { wher = (cr > 0 && cr < comp) ? cr : what; };

		func(coord.row - sizeRow / 2, regmap.topLeft.row, mapSize.row, 0);
		func(coord.col - sizeCol / 2, regmap.topLeft.col, mapSize.col, 0);
		func(coord.row + sizeRow / 2, regmap.bottomRight.row, mapSize.row, mapSize.row);
		func(coord.col + sizeCol / 2, regmap.bottomRight.col, mapSize.col, mapSize.col);

		if (regmap.topLeft.row == 0)
			regmap.bottomRight.row = min(mapSize.row - 1, sizeRow - 1);


		if (regmap.topLeft.col == 0)
			regmap.bottomRight.col = min(mapSize.col - 1, sizeCol - 1);


		if (regmap.bottomRight.row == mapSize.row - 1)
			regmap.topLeft.row = min(0, regmap.bottomRight.row - sizeRow + 1);


		if (regmap.bottomRight.col == mapSize.row - 1)
			regmap.topLeft.col = min(0, regmap.bottomRight.col - sizeCol + 1);

		return regmap;
	}

	void printBorder(const Region &rg) const
	{
		printRegion(*itHandle, rg, Color::White, Color::Black);
	}

	void printRegionIn(MapReg && regMap, Region && regCon)
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

				printCellIn(map->getCell(mapRow, mapCol, false), (short)conRow, (short)conCol);
			}
		}
	}

	void showCellBag()
	{
		showHeroBag();

		auto bag = map->getCell(hero->getCoord(), false)->getBag();

		if (bag)
			showBag(bag, { 50 , 0, 100, 100 }, currents[L"currentCellBagItem"]);
	}
};






//------------------------------

Visual::Visual() :impl(make_unique<Impl>())
{
}


Visual::~Visual()
{
}

void Visual::setMap(shared_ptr<Map> map, Unit* hero)
{
	impl->setMap(map, hero);
}

void Visual::cleanRegion(Region && regConsole)
{
	clearRect(*impl->itHandle, regConsole, ' ');
}

void Visual::printCurrentState()
{
	switch (impl->state)
	{
	case VisualState::map:
		impl->printMap();
		break;
	case VisualState::bag:
		impl->showHeroBag();
		break;
	case VisualState::cellBag:
		impl->showCellBag();
		break;
	default:
		break;
	}

	impl->changeBuffer();
}

void Visual::setState(VisualState v)
{
	impl->state = v;
}

void Visual::setCurrent(wstring name, int value)
{
	impl->currents[name] = value;
}
 