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
#include "../ConsoleApplication1/GameController.h"
#include "../ConsoleApplication1/Visual.h"
int main()
{
	setlocale(LC_ALL, "rus");

	GameController g;

	g.run();
	


	while (true) {
		int k = _getch();
		cout << endl << k << endl;
	}
	

	getchar();
    return 0;
}

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
