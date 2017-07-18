#pragma once
#include "Mover.h"
class SimpleMover : public Mover
{
public:
	SimpleMover();
	~SimpleMover();

	void moveTo(pair<size_t, size_t> &&coord) override;
};

