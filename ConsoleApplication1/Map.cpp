#include "stdafx.h"
#include "Map.h"
#include "Cell.h"
#include <unordered_map>
#include <functional>

typedef std::pair<size_t, size_t> CoordPair;

struct CoordHasher
{
	CoordHasher(size_t colCount) :colCount(colCount) {}

	size_t colCount;
	size_t operator()(const std::pair<size_t, size_t> &coords) const
	{
		return std::hash<int>()(colCount*coords.first + coords.second);
	}
};

struct CoordEqual
{
	bool operator()(const CoordPair& lhs, const CoordPair& rhs) const
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}
};



struct Map::Cells
{
	function<bool(const CoordPair&, const CoordPair&)> equaler = [](const CoordPair& lhs, const CoordPair& rhs) { return lhs.first == rhs.first && lhs.second == rhs.second; };
	function<size_t(const CoordPair&)> hasher = [this](const CoordPair& coord) { return this->colCount*coord.first + coord.second; };

	typedef std::unordered_map < std::pair<size_t, size_t>, shared_ptr<Cell>, decltype(hasher), decltype(equaler) > CellMap;

	Cells(size_t rowCount, size_t colCount):rowCount(rowCount), colCount(colCount), cells((rowCount+1)*(colCount+1), hasher, equaler)
	{
		for (size_t row = 0; row < colCount; row++) {
			for (size_t col = 0; col < colCount; col++)
			{
				cells[std::pair<size_t, size_t>(row, col)] = std::make_shared<Cell>();
			}
		}
	}

	~Cells(){}

	auto getCell(size_t row, size_t col)
	{
		return cells[std::pair<size_t, size_t>(row, col)];
	}

	auto operator()(size_t row, size_t col)
	{
		return getCell(row, col);
	}

	auto operator [](std::pair<size_t, size_t>&& coords)
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
	Impl(size_t rowCount, size_t colCount):cells(rowCount, colCount)
	{}
	Cells cells;
};

Map::Map(size_t rowCount, size_t colCount):impl(make_unique<Impl>(rowCount, colCount)){}




auto Map::getCell(size_t row, size_t col) -> shared_ptr<Cell>
{
	return impl->cells(row, col);
}
