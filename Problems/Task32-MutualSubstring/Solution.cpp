#include "stdafx.h"
#include "Solution.h"


Solution::Solution(std::string firstString, std::string secondString) :
	firstString_(firstString), secondString_(secondString)
{
	for (unsigned int firstStringIterator = 0; firstStringIterator < firstString.length(); firstStringIterator++)
	{
		for (unsigned int secondStringIterator = 0; secondStringIterator < secondString.length(); secondStringIterator++)
		{
			if (firstString[firstStringIterator] == secondString[secondStringIterator])
			{
				mutualSubstring_.push_back(firstString[firstStringIterator]);
				firstString = firstString.substr(0, firstStringIterator) + firstString.substr(firstStringIterator + 1);
				secondString = secondString.substr(0, secondStringIterator) + secondString.substr(secondStringIterator + 1);
				firstStringIterator--;
				break;
			}			
		}
	}
}


Solution::~Solution()
{
}


void Solution::printResult()
{
	std::cout << "First input string: " << firstString_ << std::endl;
	std::cout << "Second input string: " << secondString_ << std::endl;
	std::cout << "Result: " << mutualSubstring_ << std::endl;		
}
