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
#include "../Vizualizer/visUtils.h"

#include <unordered_map>
#include <functional>


using namespace std;



int main()
{
	setlocale(LC_ALL, "rus");

	auto h = GetStdHandle(STD_OUTPUT_HANDLE);
	prepareConsole(h);
	putTextToRegion(h, Region{ 1, 1, 10, 30 }, L"1 2 3 4 5 6 7 8 9 0 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50");

	getchar();
    return 0;
}

