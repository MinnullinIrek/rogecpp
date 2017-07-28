#pragma once
#include "utils.h"

class Map;
class AI;

class MapCreator
{
private:
	struct Impl;
	unique_ptr<Impl> impl;
public:
	MapCreator();
	~MapCreator();

	auto createMap(shared_ptr<AI> ai)->shared_ptr<Map>;

};

