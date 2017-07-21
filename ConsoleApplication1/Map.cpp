#include "stdafx.h"


#include <functional>
#include <unordered_map>

#include "Map.h"
#include "Cell.h"


//typedef Coords Coords;




struct Map::Cells
{
	template <typename T>
	bool coordInMap(T &&coord)
	{
		return coord.row >= 0 && coord.col >= 0 && coord.row < rowCount && coord.col <= colCount;
	}

	Cells(size_t rowCount, size_t colCount) : rowCount(rowCount), colCount(colCount), cells((rowCount + 1)*(colCount + 1), hasher, equaler)
	{
		for (size_t row = 0; row < colCount; row++) {
			for (size_t col = 0; col < colCount; col++) {
				//cells[Coords{ row, col }] = make_shared<Cell>();
			}
		}
	}

	~Cells() {}

	function<bool(const Coords&, const Coords&)> equaler = [](const Coords& lhs, const Coords& rhs) { return lhs.row == rhs.row && lhs.col == rhs.col; };
	function<size_t(const Coords&)> hasher = [this](const Coords& coord) { return this->colCount*coord.row + coord.col; };
	typedef unordered_map < Coords, shared_ptr<Cell>, decltype(hasher), decltype(equaler) > CellMap;

	template<typename T>
	auto getCell(T &&coord, bool isCreateble)-> shared_ptr<Cell>
	{
		auto &cell = cells[coord];
		if (isCreateble && !cell && coordInMap(coord))
			cell.reset(new Cell());

		return cell;
	}

	auto operator()(size_t row, size_t col, bool isCreateble)-> shared_ptr<Cell>
	{
		return getCell(Coords{ row, col }, isCreateble);
	}

	//auto operator()(Coords && coord)-> shared_ptr<Cell>
	//{
	//	return cells[(coord)];
	//}

	template<typename T>
	auto operator()(T && coord, bool isCreateble)-> shared_ptr<Cell>
	{
		return getCell(forward<T>(coord), isCreateble);
	}

	//auto operator()(const Coords & coord)-> shared_ptr<Cell>
	//{
	//	return cells[coord];
	//}



	//auto operator [](Coords&& coords)-> shared_ptr<Cell>
	//{
	//	return getCell(coords.row, coords.col);
	//}

public:


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

auto Map::getCell(size_t row, size_t col, bool isCreatable) -> shared_ptr<Cell>
{
	return impl->cells(row, col, isCreatable);
}

auto Map::getCell(Coords&& coord, bool isCreatable) -> shared_ptr<Cell>
{
	return impl->cells(move(coord), isCreatable);
}

auto Map::getCell(const Coords& coord, bool isCreatable) const -> shared_ptr<Cell>
{
	return impl->cells(coord, isCreatable);
}

auto Map::getSize() const -> Coords
{
	return Coords{ impl->cells.rowCount, impl->cells.colCount};
}


