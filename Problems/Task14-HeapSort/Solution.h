#pragma once
#include <iostream>



template <typename Type>
class Solution
{
private:
	Type* itemArray_;
	unsigned int arraySize_;
	bool(*compareFunction)(Type firstComparedItem, Type secondComparedItem);
	void convertArray(unsigned int arraySize, int limitValue);
	void fillArray(Type(* getRandomItem)(void));
public:
	void heapSort();
	Solution(Type* itemArray, unsigned int arraySize, bool (* compare)(Type firstComparedItem, Type secondCompared));
	Solution(Type (* getRandomItem)(void), unsigned int arraySize, bool (* compare)(Type firstComparedItem, Type secondCompared));
	void printArraay();
	~Solution();
};

