#pragma once
#include "utils.h"


class Cell;
class Unit;
class Map;

class Mover
{
	friend Unit;
protected:

	struct Impl;
	unique_ptr<Impl> impl;
public:

	Mover();
	Mover(shared_ptr<Map> map, shared_ptr<Cell>	  currentCell, const Coords  &coord, shared_ptr<Unit> unit);
	~Mover();

	virtual void moveTo(Coords && coord) = 0;
	shared_ptr<Cell> getCurrentCell();
	Coords  getCoord();

protected:
	void blinkTo(Coords &&coord);
	void directTo(Coords &&coord);
};

