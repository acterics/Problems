#include "stdafx.h"
#include "Solution.h"


double Solution::defaultFunction(double firstArgument, double secondArgument)
{
	return firstArgument * firstArgument + secondArgument * secondArgument;
}

double Solution::defaultSecondUpperBound(double argument)
{
	return 2 * argument - 1;
}

double Solution::measure()
{
	return (firstUpperBound_ - firstLowerBound_) * (secondUpperBound_(firstUpperBound_) - secondLowerBound_);
}

double Solution::getRandomValue(int accuracy)
{
	return (fmod(rand(), accuracy)) / accuracy;
}


Solution::Solution(double(*function)(double, double), double(*secondUpperBound)(double), double firstLowerBound, double firstUpperBound, double secondLowerBound)
{
	firstLowerBound_ = firstLowerBound;
	firstUpperBound_ = firstUpperBound;
	secondLowerBound_ = secondLowerBound;
	function_ = function;
	secondUpperBound_ = secondUpperBound;
	srand(time(0));
}


double Solution::solve(int stepsAmount, int randomAccuracy)
{
	double sum = 0;
	double firstArgument;
	double secondArgument;
	double secondUpperBound = secondUpperBound_(firstUpperBound_);
	double randomValue;
	for (int iterator = 0; iterator < stepsAmount; iterator++)
	{
		randomValue = getRandomValue(randomAccuracy);
		firstArgument = firstLowerBound_ + (firstUpperBound_ - firstLowerBound_) * randomValue;
		randomValue = getRandomValue(randomAccuracy);
		secondArgument = secondLowerBound_ + (secondUpperBound - secondLowerBound_) * randomValue;
		sum += function_(firstArgument, secondArgument);
	}
	return measure() * sum / stepsAmount;
}


Solution::~Solution()
{
}
