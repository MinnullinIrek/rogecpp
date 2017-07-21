#pragma once
//#include "stdafx.h"
#include "utils.h"

#include "../Vizualizer/visUtils.h"

class Map;
class Unit;

//typedef pair<Coords, Coords> MapReg;
class MapReg
{
public:
	struct
	{
		size_t row, col;
	}topLeft, bottomRight;

};

class Visual
{
	struct Impl;

	unique_ptr<Impl> impl;

	
public:

	Visual();
	~Visual();

	void setMap(shared_ptr<Map> map, Unit* hero);

	void printRegionIn(MapReg &&regMap, Region &&regConsole);
	void cleanRegion(Region &&regConsole);
	void printMap();
private:

	bool isInRegion(const Coords &coords);
	MapReg getRegMapForPrint();
	void printBorder(const Region &rg) const;

	void printParams();

};

