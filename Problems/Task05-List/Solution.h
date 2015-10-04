#pragma once
#include "List.h"
#include "List.cpp"
#include <iostream>
class Solution
{
private:
	List<int>* firstResultList_;
	List<int>* secondResultList_;
public:
	Solution(List<int>* inputList, int seperatingNumber);
	~Solution();
};

