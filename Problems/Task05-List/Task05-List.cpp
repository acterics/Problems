// Task05-List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"
#include <iostream>


using namespace std;
int main()
{
	List<int> *list = new List<int>();
	for (int i = 0; i < 200; i++)
	{
		list->pushBack(i);
	}

	Solution task(list, 30);


	//list->pushFront(&tempInt);

    return 0;
}

