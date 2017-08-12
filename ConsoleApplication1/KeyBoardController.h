#pragma once

enum class Direction {
	esc		= 27,
	arrow	= 224,
	arrow0	= 0,
	up		= 72,
	down	= 80,
	left	= 75,
	right	= 77,
	pgUp	= 73,
	pgDn	= 81,
	end		= 79,
	home	= 71,
	enter	= 13,
	i		= 105,
	p		= 112,
};

enum class Action
{
	up			= 1,
	down		= 2,
	left		= 4,
	right		= 8,
	upLeft		= 5,
	upRight		= 9,
	downLeft	= 6,
	downRight	= 10,
	esc			= 11,
	enter,
	inventory,
	wait,
	pickUP,
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

