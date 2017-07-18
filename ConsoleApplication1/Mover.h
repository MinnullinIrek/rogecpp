#pragma once
//#include <memory>


class Cell;
class Unit;
class Map;

using namespace std;
class Mover
{
protected:

	shared_ptr<Map>		  map;
	shared_ptr<Cell>	  currentCell;
	pair<size_t, size_t>  coord;
	shared_ptr<Unit>	  unit;


public:
	Mover();
	~Mover();

	virtual void moveTo(pair<size_t, size_t> && coord) = 0;
protected:
	void blinkTo(pair<size_t, size_t> &&coord);
};

