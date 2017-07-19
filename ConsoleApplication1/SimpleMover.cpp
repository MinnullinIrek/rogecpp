#include "stdafx.h"
#include "SimpleMover.h"


SimpleMover::SimpleMover()
{
}

SimpleMover::SimpleMover(shared_ptr<Map> map, shared_ptr<Cell> currentCell, Coords coord, shared_ptr<Unit> unit):Mover(map, currentCell, coord, unit)
{
}


SimpleMover::~SimpleMover()
{
}

void SimpleMover::moveTo(Coords &&coord)
{
	blinkTo(move(coord));
}
