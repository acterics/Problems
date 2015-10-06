#include "stdafx.h"
#include "Solution.h"





std::string Solution::eraseForPalindrome(std::string inputString, int stepsAmount)
{
	if (stepsAmount > minimalStepsAmount_)
		return inputString;
	if (isPalindrome(inputString))
	{
		if (stepsAmount < minimalStepsAmount_)
		{
			minimalStepsAmount_ = stepsAmount;
			inputString_ = inputString;
		}
		return inputString;
	}	
	for (unsigned int iterator = 0; iterator < inputString.size(); iterator++ )
	{
		//if(isPalindrome(eraseForPalindrome((inputString.substr(0, iterator) + inputString.substr(iterator + 1)), stepsAmount + 1)));

	}
}

bool Solution::isPalindrome(std::string inputString)
{
	if (inputString.length() <= 1)
		return true;
	if (inputString[0] != inputString[inputString.length() - 1])
		return false;
	return isPalindrome(inputString.substr(1, inputString.length() - 2));
}

//std::string Solution::solve()
//{
//
//}

Solution::Solution(std::string inputString)
{
	inputString_ = inputString;
	minimalStepsAmount_ = INFINITY;
}

Solution::~Solution()
{
}
