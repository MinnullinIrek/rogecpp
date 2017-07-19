#pragma once
#include "utils.h"

#include "Mover.h"

class SimpleMover : public Mover
{
public:
	SimpleMover();
	SimpleMover(shared_ptr<Map> map, shared_ptr<Cell>	  currentCell, Coords  coord, shared_ptr<Unit> unit);
	~SimpleMover();

	void moveTo(Coords &&coord) override;
};

