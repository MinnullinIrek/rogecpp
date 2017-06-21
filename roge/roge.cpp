// roge.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Cell.h"
#include "Unit.h"
#include <algorithm>

#include <vector>
struct Cells
{
	Cells(size_t rowCount, size_t colCount) :rowCount(rowCount), colCount(colCount), cells(rowCount*colCount)
{
	for (auto &cell : cells)
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
	std::vector<Cell*> cells;

};

int main()
{

	

	Cells cells1(4, 4);
	Cell*c = cells1[{2, 2}];

	Unit *sp = new Unit;
	ISpaceObject *sp0 = sp;

	std::unique_ptr<ISpaceObject> un;
	un.reset(sp);
	Cell cell;
	cell.setSpaceObject(std::move(un));
	ISpaceObject *sp2 = cell.getSpaceObject();

	Unit* u = (Unit*)sp2;

    return 0;
}

