#pragma once


class RandomGame
{
public:
	RandomGame();
	~RandomGame();

	static void init();

	int getRandom(int min = 0, int max = 10);

};

