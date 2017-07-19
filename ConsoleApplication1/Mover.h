#pragma once
//#include <memory>
#include "utils.h"


class Cell;
class Unit;
class Map;

using namespace std;
class Mover
{
	friend Unit;
protected:

	shared_ptr<Map>		  map;
	shared_ptr<Cell>	  currentCell;
	Coords  coord;
	shared_ptr<Unit>	  unit;


public:

	Mover();
	Mover(shared_ptr<Map> map, shared_ptr<Cell>	  currentCell, Coords  coord, shared_ptr<Unit> unit);
	~Mover();

	virtual void moveTo(Coords && coord) = 0;
	shared_ptr<Cell> getCurrentCell();
	Coords  getCoord();

protected:
	void blinkTo(Coords &&coord);
};

