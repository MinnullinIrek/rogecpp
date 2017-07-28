#pragma once
#include "utils.h"

class Unit;

class AI
{

	struct Impl;

	unique_ptr<Impl> impl;

public:
	AI();
	~AI();

	auto addEnemy(shared_ptr<Unit> enemy) -> void;
	auto addHero(shared_ptr<Unit> hero) -> void;
	auto go() -> void;

};

