#pragma once
//#include "stdafx.h"

#include "../Vizualizer/visUtils.h"

class Map;

class Visual
{
	struct Impl;

	unique_ptr<Impl> impl;


public:
	Visual();
	~Visual();

	void setMap(shared_ptr<Map> map);

	void printRegionIn(Region &&regMap, Region &&regConsole);

private:
};

