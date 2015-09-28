// Task04-MonteCarloMethod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"
#include <iostream>
#define DEFAULT_RESULT_VALUE 0.4583333333333

int main()
{
	double tempValue = 0;
	Solution* task04 = new Solution(Solution::defaultFunction, Solution::defaultSecondUpperBound);

	std::cout << "0.5 <= x <= 1; 0 <= y <= 1" << std::endl;
	std::cout << "I = " << DEFAULT_RESULT_VALUE << std::endl;
	for (int i = 1; i <= 10; i++)
	{
		tempValue = task04->solve();
		std::cout << i << ". I(rand) = " << tempValue << " error = " << DEFAULT_RESULT_VALUE - tempValue << std::endl;
	}
	return 0;
}

