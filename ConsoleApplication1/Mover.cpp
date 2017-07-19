#include "stdafx.h"
#include "Mover.h"
#include "Map.h"
#include "Cell.h"
#include "unit.h"

Mover::Mover()
{
}

Mover::Mover(shared_ptr<Map> map, shared_ptr<Cell> currentCell, pair<size_t, size_t> coord, shared_ptr<Unit> unit):
	map(map), currentCell(currentCell), coord(coord), unit(unit)
{
}


Mover::~Mover()
{
}

shared_ptr<Cell> Mover::getCurrentCell()
{
	return currentCell;
}

pair<size_t, size_t> Mover::getCoord()
{
	return coord;
}

void Mover::blinkTo(pair<size_t, size_t> &&cord)
{
	
	auto cell = map->getCell(pair<size_t, size_t>(cord));
	
	if (cell.get() != nullptr && cell->isEmpty())
	{
		currentCell->resetSpaceObject();
		cell->setSpaceObject(unit);
		currentCell = cell;
		this->coord = cord;
	}
}

