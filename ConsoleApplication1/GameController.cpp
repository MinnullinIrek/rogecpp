#include "stdafx.h"
#include <functional>

#include "KeyBoardController.h"
#include "GameController.h"
#include "unit.h"
#include "Map.h"
#include "Visual.h"
#include "MapCreator.h"
#include "Cell.h"

struct GameController::Impl
{
	Impl()
	{
		MapCreator m;
		map = m.createMap();
		//shared_ptr<ISpaceObject> sp = map->getCell(0, 0)->getSpaceObject();
		auto del = [](Unit*unit) {};
		hero = unique_ptr<Unit, decltype(del)>( (Unit*)map->getCell(0, 0)->getSpaceObject().get(), del );

		//hero = map->getCell(0, 0)->getSpaceObject();
		visual = make_shared<Visual>();
		visual->setMap(map);
	}

	unique_ptr<Unit, function<void(Unit*)>> hero;
	shared_ptr<Map> map;
	shared_ptr<Visual> visual;
};

GameController::GameController():impl(make_unique<Impl>())
{
}


GameController::~GameController()
{
}

void GameController::run()
{


	Action act = Action::wait;
	

	while (act != Action::esc)
	{
		impl->visual->printRegionIn(Region{ 0, 0, 10, 10 }, Region{ 0,0,10,10 });
		auto coord = impl->hero->getCoord();
		act = KeyBoardController::getCh();

		switch (act)
		{
		case Action::up:
			impl->hero->moveTo(coord.first - 1, coord.second);
			break;
		case Action::down:
			impl->hero->moveTo(coord.first + 1, coord.second);
			break;
		case Action::left:
			impl->hero->moveTo(coord.first , coord.second - 1);
			break;
		case Action::right:
			impl->hero->moveTo(coord.first, coord.second+1);
			break;
		case Action::upLeft:
			impl->hero->moveTo(coord.first - 1, coord.second-1);
			break;
		case Action::upRight:
			impl->hero->moveTo(coord.first - 1, coord.second+1);
			break;
		case Action::downLeft:
			impl->hero->moveTo(coord.first + 1, coord.second-1);
			break;
		case Action::downRight:
			impl->hero->moveTo(coord.first + 1, coord.second+1);
			break;
		case Action::esc:
			break;
		case Action::enter:
			break;
		case Action::wait:
			break;
		default:
			break;
		}

	}



}
