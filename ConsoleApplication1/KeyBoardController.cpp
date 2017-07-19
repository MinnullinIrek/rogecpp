#include "stdafx.h"
#include "KeyBoardController.h"
#include <conio.h>





KeyBoardController::KeyBoardController()
{
}


KeyBoardController::~KeyBoardController()
{
}

Action KeyBoardController::getCh()
{
	int key = _getch();

	if (key == static_cast<int>(Direction::arrow) || key == static_cast<int>(Direction::arrow0)) {
		key = _getch();
	}
	
	Action a = Action::wait;
	
	switch (key)
	{
	case static_cast<int>(Direction::left) :
		a = Action::left;
		break;
	case static_cast<int>(Direction::right) :
		a = Action::right;
		break;
	case static_cast<int>(Direction::up):
		a = Action::up;
		break;
	case static_cast<int>(Direction::down) :
		a = Action::down;
		break;
	case static_cast<int>(Direction::end) :
		a = Action::downLeft;
		break;
	case static_cast<int>(Direction::home) :
		a = Action::upLeft;
		break;
	case static_cast<int>(Direction::pgUp) :
		a = Action::upRight;
		break;
	case static_cast<int>(Direction::pgDn) :
		a = Action::downRight;
		break;
		default:
		break;
	}
	return a;
}
