#pragma once
#include <memory>
#include "Map.h"
#include "Cell.h"
#include "unit.h"

using namespace std;
class Mover
{
	weak_ptr<Map>		map;
	weak_ptr<Cell>		currentCell;
	shared_ptr<Unit>	unit;

public:
	Mover();
	~Mover();



};

