#pragma once
//#include "stdafx.h"

#include "../Vizualizer/visUtils.h"

class Visual
{
	struct Impl;

	unique_ptr<Impl> impl;


public:
	Visual();
	~Visual();

	void printRegionIn(Region &&regMap, Region &&regConsole);

private:
};

