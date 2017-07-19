#pragma once
#include "Mover.h"
class SimpleMover : public Mover
{
public:
	SimpleMover();
	SimpleMover(shared_ptr<Map> map, shared_ptr<Cell>	  currentCell, pair<size_t, size_t>  coord, shared_ptr<Unit> unit);
	~SimpleMover();

	void moveTo(pair<size_t, size_t> &&coord) override;
};

