// Task14-HeapSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <ctime>
#include "Solution.h"
#include "Solution.cpp"
#define MAXIMUM_INTEGER_VALUE 100
#define MINIMAL_INTEGER_VALUE 0


int getRandomInteger()
{
	return MINIMAL_INTEGER_VALUE + rand() % MAXIMUM_INTEGER_VALUE;
}

bool compare(int firstValue, int secondValue)
{
	if (firstValue < secondValue)
		return true;
	else
		return false;
}

int main()
{
	srand(time(NULL));
	int(*getRandomInt)(void) = getRandomInteger;
	bool(*compareFunction)(int firstValue, int secondValue) = compare;
	unsigned int arraySize = 10;
	Solution<int>* s = new Solution<int>(getRandomInt, arraySize, compareFunction);
	s->printArraay();
	s->heapSort();
	s->printArraay();
    return 0;

}



