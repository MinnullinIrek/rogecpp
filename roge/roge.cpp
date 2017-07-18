// roge.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <algorithm>

#include <vector>



#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iterator>
#include <Windows.h>
//#include "../Vizualizer/visUtils.h"

#include <unordered_map>
#include <functional>
#include <memory>


using namespace std;

class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

#include "../ConsoleApplication1/Map.h"
//#include "../ConsoleApplication1/Cell.h"
#include "../ConsoleApplication1/MapCreator.h"
#include "../ConsoleApplication1/Visual.h"
int main()
{
	setlocale(LC_ALL, "rus");

	MapCreator cr;

	auto mp = cr.createMap();
	Visual v;
	v.setMap(mp);
	v.printRegionIn(Region{ 0,0,10,10 }, Region{ 0, 0, 10, 10 });


	shared_ptr<MyClass> mycl = make_shared<MyClass>();

	weak_ptr<MyClass> wmycl;

	wmycl = mycl;


	auto h = GetStdHandle(STD_OUTPUT_HANDLE);
	prepareConsole(h);
	putTextToRegion(h, Region{ 1, 1, 10, 30 }, L"1 2 3 4 5 6 7 8 9 0 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50");

	getchar();
    return 0;
}

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
