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

class MyClass
{
public:
	int a = 5;
	int b = 10;

};

struct MyHash {
	int a = 9;
	MyHash(int a):a(a)
	{

	}
	std::size_t operator()(const pair<size_t, size_t>& k) const
	{
		return static_cast<std::size_t>(k.first) ^ static_cast<std::size_t>(k.second);
	}
};

template<>
struct std::hash<pair<size_t, size_t>>
{
	std::size_t operator()(const MyClass& k) const;
};

int main()
{
	setlocale(LC_ALL, "rus");

	int a = 10;

	std::unordered_map<pair<size_t, size_t>, std::string, MyHash> m(10, MyHash(10));
	
	
	function<bool(const pair<size_t, size_t>&)> a2 = [&a](const pair<size_t, size_t>& k) ->size_t
	{
		a = a + 1;
		return static_cast<std::size_t>(k.first) + static_cast<std::size_t>(k.second);
	};
		

	std::unordered_map < pair<size_t, size_t>, std::string, decltype(a2)> m2(10, a2);

	m2[pair<size_t, size_t>(2, 3)] = 10;

	for (auto& it : m2)
	{
		it.second = "qwet";
	}


	auto h = GetStdHandle(STD_OUTPUT_HANDLE);
	prepareConsole(h);
	putTextToRegion(h, Region{ 1, 1, 10, 30 }, L"1 2 3 4 5 6 7 8 9 0 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50");



	





	getchar();
    return 0;
}

