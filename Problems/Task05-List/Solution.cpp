#include "stdafx.h"
#include "Solution.h"





Solution::Solution(List<int>* inputList, int seperatingNumber)
{
	firstResultList_ = new List<int>();
	secondResultList_ = new List<int>();

	List<int>::Node* current = inputList->head();
	while (current)
	{
		
		current = inputList->tail();
		if (*current->data() <= seperatingNumber)
			firstResultList_->pushBack(current);
		else
			secondResultList_->pushBack(current);
		current = inputList->head();
		while (current->next()->next())
		{
			current = current->next();
		}
		inputList->setTail(current);
		
	}
	std::cout << *firstResultList_;
	std::cout << *secondResultList_;
}

Solution::~Solution()
{
}
