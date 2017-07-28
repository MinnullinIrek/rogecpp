#include "stdafx.h"
#include "utils.h"
#include <cmath>

auto getDistanceCoord(const Coords &c1, const Coords &c2) -> double
{
	return sqrt(pow(c2.col - c1.col, 2) + pow(c2.row - c1.row, 2));
}
