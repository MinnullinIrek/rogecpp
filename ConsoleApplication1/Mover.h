#pragma once
//#include <memory>


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
	pair<size_t, size_t>  coord;
	shared_ptr<Unit>	  unit;


public:

	Mover();
	Mover(shared_ptr<Map> map, shared_ptr<Cell>	  currentCell, pair<size_t, size_t>  coord, shared_ptr<Unit> unit);
	~Mover();

	virtual void moveTo(pair<size_t, size_t> && coord) = 0;
	shared_ptr<Cell> getCurrentCell();
	pair<size_t, size_t>  getCoord();

protected:
	void blinkTo(pair<size_t, size_t> &&coord);
};

