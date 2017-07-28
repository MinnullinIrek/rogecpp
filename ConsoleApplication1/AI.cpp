#include "stdafx.h"
#include <list>
#include <functional>

#include "AI.h"
#include "unit.h"


struct AI::Impl
{
	list<shared_ptr<Unit>> eneimies;
	shared_ptr<Unit> hero;
};

AI::AI():impl(make_unique<Impl>())
{
}


AI::~AI()
{
}

auto AI::addEnemy(shared_ptr<Unit> enemy) -> void
{
	impl->eneimies.push_back(enemy);
}

auto AI::addHero(shared_ptr<Unit> hero) -> void
{
	impl->hero = hero;
}

auto AI::go() -> void
{
	auto radius = 4;

	auto getDistance = [](shared_ptr<Unit> hero, shared_ptr<Unit> enemy)
	{
		Coords heroCoord = hero->getCoord();
		Coords enemyCoord = enemy->getCoord();
		return getDistanceCoord(heroCoord, enemyCoord);
	};

	auto doSomething = [](shared_ptr<Unit> attacker, shared_ptr<Unit> defender)
	{
		Coords attackerCoord = attacker->getCoord();
		Coords defenderCoord = defender->getCoord();
		attacker->directTo(defenderCoord.row, defenderCoord.col);
	};


	auto attack = [radius](shared_ptr<Unit> hero, shared_ptr<Unit> enemy, function<double(shared_ptr<Unit>, shared_ptr<Unit>)> getDistance, function<void(shared_ptr<Unit>, shared_ptr<Unit>)> doSomething)
	{
		if (getDistance(hero, enemy) <= radius){
			doSomething(enemy, hero);
		}
	} ;

	for (auto unit : impl->eneimies) {
		attack(impl->hero, unit, getDistance, doSomething);
	}
}
