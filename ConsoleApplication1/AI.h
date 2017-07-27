#pragma once
#include "utils.h"

class AI
{

	struct Impl;

	unique_ptr<Impl> impl;

public:
	AI();
	~AI();
};

