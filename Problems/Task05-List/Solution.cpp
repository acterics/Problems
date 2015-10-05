#include "stdafx.h"
#include "Solution.h"


void Solution::fillList(int listSize)
{
	for (int iterator = 0; iterator < listSize; iterator++)
		inputList_->pushBack(MINIMAL_RANDOM_VALUE + rand() % MAXIMUM_RANDOM_VALUE);
}

Solution::Solution(List::List<int>* inputList, int seperatingValue) :
	seperatingValue_(seperatingValue)
{
	firstResultList_ = new List::List<int>();
	secondResultList_ = new List::List<int>();
	inputList_ = new List::List<int>(inputList);
	std::cout << "Input list: " << *inputList_;
}

Solution::Solution(int seperatingValue, int listSize) :
	seperatingValue_(seperatingValue)
{
	srand(time(NULL));
	firstResultList_ = new List::List<int>();
	secondResultList_ = new List::List<int>();
	inputList_ = new List::List<int>();
	fillList(listSize);
	std::cout << "Input list: " << *inputList_;

}

Solution::~Solution()
{
}

void Solution::solve()
{
	List::List<int>::Node * current = inputList_->head();
	List::List<int>::Node * tempNode = current;
	while (current)
	{
		tempNode = current;
		current = current->next();
		tempNode->setNext(nullptr);
		if (*tempNode->data() < seperatingValue_)
			firstResultList_->pushBack(tempNode);
		else
			secondResultList_->pushBack(tempNode);
	}
}

void Solution::printResult()
{
	std::cout << *inputList_;
	std::cout << "< " << seperatingValue_ << ": " << *firstResultList_;
	std::cout << ">= " << seperatingValue_ << ": " << *secondResultList_;

}

void Solution::clearData()
{
	inputList_->clear();
	firstResultList_->clear();
	secondResultList_->clear();
}
