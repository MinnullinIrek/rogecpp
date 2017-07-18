#include "stdafx.h"
#include "Mover.h"
#include "Map.h"
#include "Cell.h"
#include "unit.h"

Mover::Mover()
{
}


Mover::~Mover()
{
}

void Mover::blinkTo(pair<size_t, size_t> &&cord)
{
	auto cell = map->getCell(cord);
	
	if (cell->isEmpty())
	{
		cell->setSpaceObject(unit);
		currentCell = cell;
		this->coord = cord;
	}
}

