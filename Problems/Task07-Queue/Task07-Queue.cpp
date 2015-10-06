// Task07-Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "QueueDll.h"
#include <ctime>
#define EXPERIMENTS_AMOUNT 100
#define MAXIMUM_RANDOM_VALUE 1000
#define MINIMAL_RANDOM_VALUE 0

int getRandomInteger()
{
	return MINIMAL_RANDOM_VALUE + rand() % MAXIMUM_RANDOM_VALUE;
}
bool compare(int firstInteger, int secondInteger)
{
	if (firstInteger > secondInteger)
		return true;
	return false;
}
int main()
{
	srand(time(NULL));
	Queue::Queue<int> * p = new Queue::Queue<int>(500, getRandomInteger);
	float startTime = clock();
	for (int iterator = 0; iterator < EXPERIMENTS_AMOUNT; iterator++)
	{
		p->quickSort(compare);
		p->reFillQueue(getRandomInteger);
	}
	
	float endTime = clock() - startTime;

	std::cout << "QuickSort sorted queue in " << endTime << std::endl;

	p->reFillQueue(getRandomInteger);
	startTime = clock();
	for (int iterator = 0; iterator < EXPERIMENTS_AMOUNT; iterator++)
	{
		p->insertSort(compare);
		p->reFillQueue(getRandomInteger);
	}
	endTime = clock() - startTime;

	std::cout << "InsertSort sorted queue in " << endTime << std::endl;


    return 0;
}

