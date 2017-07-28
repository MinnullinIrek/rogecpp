#include "stdafx.h"
#include "Mover.h"
#include "Map.h"
#include "Cell.h"
#include "unit.h"

struct Mover::Impl
{
	Impl(shared_ptr<Map> map, shared_ptr<Cell> currentCell, Coords coord, shared_ptr<Unit> unit) :map(map), currentCell(currentCell), coord(coord), unit(unit)
	{}
	shared_ptr<Map>		  map;
	shared_ptr<Cell>	  currentCell;
	Coords  coord;
	shared_ptr<Unit>	  unit;
};

Mover::Mover()
{
}

Mover::Mover(shared_ptr<Map> map, shared_ptr<Cell> currentCell, const Coords &coord, shared_ptr<Unit> unit) : impl(make_unique<Impl>(map, currentCell, coord, unit))
{
}


Mover::~Mover()
{
}

shared_ptr<Cell> Mover::getCurrentCell()
{
	return impl->currentCell;
}

Coords Mover::getCoord()
{
	return impl->coord;
}

void Mover::blinkTo(Coords &&cord)
{
	auto cell = impl->map->getCell(Coords(cord), true);

	if (cell.get() != nullptr) {
		if (cell->isEmpty()) {
			impl->currentCell->resetSpaceObject();
			cell->setSpaceObject(impl->unit);
			impl->currentCell = cell;
			impl->coord = cord;
		}
		else
		{
			impl->unit->cooperator(impl->unit, cell->getSpaceObject());
		}
	}
}

void Mover::directTo(Coords && coordTo)
{
	Coords newCoord = impl->coord;
	if (newCoord.col < coordTo.col)
	{
		newCoord.col++;
	}

	//newCoord.col = newCoord.col + (coordTo.col - newCoord.col) / abs((coordTo.col - newCoord.col);

}

