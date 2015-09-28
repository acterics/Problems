#include "stdafx.h"
#include "Solution.h"



Solution::Solution(double accuracy)
{
	accuracy_ = accuracy;
}

Solution::~Solution()
{
}

double Solution::solve(double argument)
{
	while (argument >= 2 * M_PI || argument <= -2 * M_PI)
		argument = fmod(argument, 2 * M_PI);

	if (argument > M_PI / 4 || argument < -M_PI / 4)
		return 2 * pow(solve(argument / 2), 2) - 1;
	
	double factorial = 0;
	double factorialValue = 1;
	double currentSum = 1;
	double previousSum = 0;
	int iterator = 1;
	while (fabs(previousSum - currentSum) >= accuracy_)
	{
		previousSum = currentSum;
		factorialValue *= (factorial + 1) * (factorial + 2);
		factorial += 2;
		currentSum += pow(-1, iterator) * pow(argument, 2 * iterator) / factorialValue;
		iterator++;
	}
	return currentSum;
}
