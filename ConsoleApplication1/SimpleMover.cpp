#include "stdafx.h"
#include "SimpleMover.h"


SimpleMover::SimpleMover()
{
}

SimpleMover::SimpleMover(shared_ptr<Map> map, shared_ptr<Cell> currentCell, pair<size_t, size_t> coord, shared_ptr<Unit> unit):Mover(map, currentCell, coord, unit)
{
}


SimpleMover::~SimpleMover()
{
}

void SimpleMover::moveTo(pair<size_t, size_t> &&coord)
{
	blinkTo(move(coord));
}
