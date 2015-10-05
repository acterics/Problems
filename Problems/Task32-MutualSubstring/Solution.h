#pragma once
#include <string>
#include <iostream>

class Solution
{
private:
	std::string firstString_;
	std::string secondString_;
	std::string mutualSubstring_;
public:
	Solution(std::string firstString, std::string secondString);
	void printResult();
	~Solution();
};

