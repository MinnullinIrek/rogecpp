#include "stdafx.h"
#include "RandomGame.h"
#include <random>
//#include <cstdlib>
#include <time.h>

RandomGame::RandomGame()
{

}


RandomGame::~RandomGame()
{
}

void RandomGame::init()
{
	srand((unsigned int)time(nullptr));
}

int RandomGame::getRandom(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}
