#pragma once


class RandomGame
{
public:
	RandomGame();
	~RandomGame();

	static void init();

	static int getRandom(int min = 0, int max = 10);

};

