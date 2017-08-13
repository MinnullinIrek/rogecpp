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

enum class VisualState
{
	map,
	bag,
	cellBag,
};


class Visual
{
	struct Impl;

	unique_ptr<Impl> impl;


public:

	Visual();
	~Visual();

	void setMap(shared_ptr<Map> map, Unit* hero);

	void cleanRegion(Region &&regConsole);
	
	void printCurrentState();
	void setState(VisualState v);
	void setCurrent(wstring name, int value);

private:
};

