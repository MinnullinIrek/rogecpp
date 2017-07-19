#include "stdafx.h"


#include <functional>
#include <unordered_map>

#include "Map.h"
#include "Cell.h"


typedef Coords CoordPair;

//struct Map::Impl
//{
//
//};


struct Map::Cells
{
	Cells(size_t rowCount, size_t colCount) : rowCount(rowCount), colCount(colCount), cells((rowCount + 1)*(colCount + 1), hasher, equaler)
	{
		for (size_t row = 0; row < colCount; row++) {
			for (size_t col = 0; col < colCount; col++) {
				cells[Coords(row, col)] = make_shared<Cell>();
			}
		}
	}

	~Cells() {}

	function<bool(const CoordPair&, const CoordPair&)> equaler = [](const CoordPair& lhs, const CoordPair& rhs) { return lhs.first == rhs.first && lhs.second == rhs.second; };
	function<size_t(const CoordPair&)> hasher = [this](const CoordPair& coord) { return this->colCount*coord.first + coord.second; };
	typedef unordered_map < Coords, shared_ptr<Cell>, decltype(hasher), decltype(equaler) > CellMap;




	auto getCell(size_t row, size_t col)-> shared_ptr<Cell>
	{
		return cells.at(Coords(row, col));
	}

	auto operator()(size_t row, size_t col)-> shared_ptr<Cell>
	{
		return getCell(row, col);
	}

	auto operator()(Coords && coord)-> shared_ptr<Cell>
	{
		return cells[(coord)];
	}

	auto operator()(const Coords & coord)-> shared_ptr<Cell>
	{
		return cells[coord];
	}

	auto operator [](Coords&& coords)-> shared_ptr<Cell>
	{
		return getCell(coords.first, coords.second);
	}

private:


	const size_t	rowCount = 0;
	const size_t	colCount = 0;
	CellMap cells;
};

struct Map::Impl
{
	Impl(size_t rowCount, size_t colCount):cells(rowCount, colCount){}

	~Impl() {}
	Cells cells;
};


Map::Map(size_t rowCount, size_t colCount):impl(make_unique<Impl>(rowCount, colCount))
{

}

Map::~Map()
{

}

auto Map::getCell(size_t row, size_t col) -> shared_ptr<Cell>
{
	return impl->cells(row, col);
}

auto Map::getCell(Coords&& coord) -> shared_ptr<Cell>
{
	return impl->cells(move(coord));
}

auto Map::getCell(const Coords& coord) const -> shared_ptr<Cell>
{
	return impl->cells(coord);
}


