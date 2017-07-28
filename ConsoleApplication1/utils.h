#pragma once
#include <string>
#include <memory>



using namespace std;
//typedef pair<size_t, size_t> Coords;
typedef int crd;

struct Coords
{
	crd row, col;
};

auto getDistanceCoord(const Coords &c1, const Coords &c2) -> double;
