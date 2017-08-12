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

	void getCoord(Coords &cd, Action act)
	{
		
		if (static_cast<int>(act) & static_cast<int>(Action::left))
			cd.col--;
		else if (static_cast<int>(act) & static_cast<int>(Action::right))
			cd.col++;

		if (static_cast<int>(act) & static_cast<int>(Action::down))
			cd.row++;
		else if (static_cast<int>(act) & static_cast<int>(Action::up))
			cd.row--;
	}

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
	VisualState state = VisualState::map;
	int currentItem = 0;

	impl->visual->printCurrentState();

	auto setState = [this, &state](VisualState vstate)
	{
		state = vstate;
		impl->visual->setState(vstate);
	};

	auto moveTo = [state, this](Action act)
	{
		if (state == VisualState::map) {
			auto coord = impl->hero->getCoord();
			impl->getCoord(coord, act);
			impl->hero->moveTo(coord.row, coord.col);
		}
		else if (state == VisualState::bag)
		{
			//todo
		}
	};


	while (true)
	{
		act = KeyBoardController::getCh();

		switch (act)
		{
		case Action::up:
		case Action::down:
		case Action::left:
		case Action::right:
		case Action::upLeft:
		case Action::upRight:
		case Action::downLeft:
		case Action::downRight:
			moveTo(act);
			break;
		case Action::esc:
			setState(VisualState::map);
			break;
		case Action::enter:
			break;
		case Action::wait:
			break;
		case Action::inventory:
			setState(VisualState::bag);
			break;
		case Action::pickUP:
			setState(VisualState::cellBag);
			break;
		default:
			break;
		}
		impl->ai->go();
		impl->visual->printCurrentState();
	}



}
