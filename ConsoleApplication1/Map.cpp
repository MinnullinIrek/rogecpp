#include "stdafx.h"
#include "Map.h"
#include "Cell.h"
#include <unordered_map>

struct Map::Cells
{
	Cells(size_t rowCount, size_t colCount):rowCount(rowCount), colCount(colCount), cells(rowCount*colCount)
	{
		for (auto cell : cells)
			cell = new Cell;
	}

	~Cells()
	{
		for (auto cell : cells)
			delete cell;
	}

	auto getCell(size_t row, size_t col)
	{
		return cells[rowCount*col + row];
	}

	auto operator [](std::pair<size_t, size_t>&& coords)
	{
		return getCell(coords.first, coords.second);
	}

private:


	const size_t	rowCount = 0;
	const size_t	colCount = 0;
	const std::vector<Cell*> cells;

	

};

struct Map::Impl
{
	Impl(size_t rowCount, size_t colCount):cells(std::make_unique<Cells>(rowCount, colCount))
	{
		

		//for (auto c: cells)
		{
			
		}
	}
	std::unique_ptr<Cells> cells;
};

Map::Map()
{
}


Map::~Map()
{
}
