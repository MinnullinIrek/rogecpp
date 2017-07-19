#pragma once
//#include "stdafx.h"
#include "utils.h"

#include "../Vizualizer/visUtils.h"

class Map;
class Unit;

class Visual
{
	struct Impl;

	unique_ptr<Impl> impl;

	const size_t sizeRow = 10;
	const size_t sizeCol = 10;

public:

	Visual();
	~Visual();

	void setMap(shared_ptr<Map> map, Unit* hero);

	void printRegionIn(Region &&regMap, Region &&regConsole);
	void cleanRegion(Region &&regConsole);
	void printMap();
private:
};

