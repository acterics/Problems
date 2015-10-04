#pragma once
#include <string>
#include <iostream>


class Solution
{
private:
	std::string inputString_;
	int minimalStepsAmount_;
	std::string eraseForPalindrome(std::string inputString, int stepsAmount);
	
public:
	bool isPalindrome(std::string inputString);
	std::string solve();
	Solution(std::string inputString);

	~Solution();
};

