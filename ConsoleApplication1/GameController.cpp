#include "stdafx.h"
#include <functional>

#include "KeyBoardController.h"
#include "GameController.h"
#include "unit.h"
#include "Map.h"
#include "Visual.h"
#include "MapCreator.h"
#include "Cell.h"
#include "AI.h"

struct GameController::Impl
{
	Impl():ai(make_unique<AI>())
	{
		MapCreator m;

		map = m.createMap(ai);
		//shared_ptr<ISpaceObject> sp = map->getCell(0, 0)->getSpaceObject();
		auto del = [](Unit*unit) {};
		hero = unique_ptr<Unit, decltype(del)>((Unit*)map->getCell(0, 0, false)->getSpaceObject().get(), del);

		//hero = map->getCell(0, 0)->getSpaceObject();
		visual = make_shared<Visual>();
		visual->setMap(map, hero.get());
	}

	unique_ptr<Unit, function<void(Unit*)>> hero;
	shared_ptr<Map> map;
	shared_ptr<Visual> visual;
	shared_ptr<AI> ai;
};

GameController::GameController() :impl(make_unique<Impl>())
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
		impl->visual->printMap();
		auto coord = impl->hero->getCoord();
		act = KeyBoardController::getCh();

		switch (act)
		{
		case Action::up:
			impl->hero->moveTo(coord.row - 1, coord.col);
			break;
		case Action::down:
			impl->hero->moveTo(coord.row + 1, coord.col);
			break;
		case Action::left:
			impl->hero->moveTo(coord.row, coord.col - 1);
			break;
		case Action::right:
			impl->hero->moveTo(coord.row, coord.col + 1);
			break;
		case Action::upLeft:
			impl->hero->moveTo(coord.row - 1, coord.col - 1);
			break;
		case Action::upRight:
			impl->hero->moveTo(coord.row - 1, coord.col + 1);
			break;
		case Action::downLeft:
			impl->hero->moveTo(coord.row + 1, coord.col - 1);
			break;
		case Action::downRight:
			impl->hero->moveTo(coord.row + 1, coord.col + 1);
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
		impl->ai->go();

	}



}
