#pragma once
#include "ListDll.h"
#include <ctime>
#define MAXIMUM_RANDOM_VALUE 100
#define MINIMAL_RANDOM_VALUE 0


class Solution
{
private:
	List::List<int> * inputList_;
	List::List<int> * firstResultList_;
	List::List<int> * secondResultList_;
	int seperatingValue_;
	void fillList(int listSize);
public:
	Solution(List::List<int>* inputList, int seperatingValue);
	Solution(int seperatingValue, int listSize);
	void solve();
	void printResult();
	void clearData();
	~Solution();
};

