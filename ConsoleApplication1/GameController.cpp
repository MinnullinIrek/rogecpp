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
#include "Bag.h"

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

	void getCurrentItem(int & currentItem, Action act, shared_ptr<Bag> bag)
	{
		if (bag) {
			currentItem += ((static_cast<int>(act) & static_cast<int>(Action::down)) ? 1 : 0) - ((static_cast<int>(act) & static_cast<int>(Action::up)) ? 1 : 0);
			currentItem = (currentItem < 0) ? 0 : currentItem;
			currentItem = (currentItem >= bag->getSize()) ? bag->getSize() - 1 : currentItem;
		}
		else {
			currentItem = 0;
		}
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
	int currentItemInBag = 0;

	impl->visual->printCurrentState();

	auto setState = [this, &state](VisualState vstate)
	{
		state = vstate;
		impl->visual->setState(vstate);
	};

	auto enter = [this, &state, &currentItemInBag, &currentItem]()
	{
		if (state == VisualState::cellBag)
		{
			impl->hero->pickUp(impl->map->getCell(move(impl->hero->getCoord()), false)->getBag(), currentItemInBag);
		}
		else if(state == VisualState::bag)
		{
			int i = 0;
			impl->hero->getBag()->forEach([&i, &currentItem, this](shared_ptr<Item> item) {
				
				if (i == currentItem) {
					impl->hero->wearItem(item, L"weapon");
					return BagItemDo::stop;
				}

				i++;
				return BagItemDo::next;
			});
			//impl->hero->wearItem();
		}

	};

	
	auto moveTo = [&currentItemInBag, &currentItem, &state, this](Action act)
	{
		if (state == VisualState::map) {
			auto coord = impl->hero->getCoord();
			impl->getCoord(coord, act);
			impl->hero->moveTo(coord.row, coord.col);
		}
		else if (state == VisualState::bag) {

			impl->getCurrentItem(currentItem, act, impl->hero->getBag());
			impl->visual->setCurrent(L"currentBagItem", currentItem );
		}
		else if (state == VisualState::cellBag) {
			impl->getCurrentItem(currentItemInBag, act, impl->map->getCell(move(impl->hero->getCoord()), false)->getBag());
			impl->visual->setCurrent(L"currentCellBagItem", currentItemInBag);
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
			enter();
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
