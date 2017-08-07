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
#include <array>


using namespace std;

int *b = new int;

class A2
{
public:
	A2() { cout << "A()"; }
	~A2() { cout << "~A()"; }

};

class MyClass
{
public:
	MyClass(A2 *a);
	virtual ~MyClass() = default;

	A2 * a = new A2;

private:

};




#include "../ConsoleApplication1/Map.h"
#include "../ConsoleApplication1/GameController.h"
#include "../ConsoleApplication1/Visual.h"
#include "../ConsoleApplication1/RandomGame.h"


int main()
{
	
	RandomGame r;
	r.init();

	while (true)
	{
		_getch();
		printf("%d\n",r.getRandom());

	}

	array<int, 3> ar1 = {1, 2, 3};
	array<int, 3> ar2 = { 3, 4, 5 };

	ar1 = ar2;

	std::wstring{ L"sasda" };


	setlocale(LC_ALL, "rus"); \
		A2* a = new A2;
	{

		MyClass m(a);
	}
	b;

	GameController g;

	g.run();
	


	while (true) {
		int k = _getch();
		cout << endl << k << endl;
	}
	

	getchar();
    return 0;
}

MyClass::MyClass(A2 *a):a(a)
{

}
