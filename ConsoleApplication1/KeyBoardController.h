#pragma once

enum class Direction {
	esc = 27,
	arrow = 224,
	arrow0 = 0,
	up = 72,
	down = 80,
	left = 75,
	right = 77,
	pgUp = 73,
	pgDn = 81,
	end = 79,
	home = 71,
	enter = 13,
};

enum class Action
{
	up,
	down,
	left,
	right,
	upLeft,
	upRight,
	downLeft,
	downRight,
	esc,
	enter,
	wait
};

class KeyBoardController
{
	//struct Impl;

	//unique_ptr<Impl> impl;

public:
	KeyBoardController();
	~KeyBoardController();

	static Action getCh();

};

