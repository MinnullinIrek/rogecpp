#include "stdafx.h"
#include "SimpleMover.h"


SimpleMover::SimpleMover()
{
}


SimpleMover::~SimpleMover()
{
}

void SimpleMover::moveTo(pair<size_t, size_t> &&coord)
{
	blinkTo(move(coord));
}
