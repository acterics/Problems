#pragma once
#include <iostream>



template <typename Type>
class Solution
{
private:
	Type* itemArray_;
	unsigned int arraySize_;
	bool(*compareFunction)(Type firstComparedItem, Type secondComparedItem);
	void heapify(unsigned int arraySize, int currentPosition);
	void buildHeap();
	void fillArray(Type(* getRandomItem)(void));
	int leftSonPosition(int position);
	int rightSonPosition(int position);
	void swap(int firstItemPosition, int secondItemPosition);
public:
	void heapSort();
	Solution(Type* itemArray, unsigned int arraySize, bool (* compare)(Type firstComparedItem, Type secondCompared));
	Solution(Type (* getRandomItem)(void), unsigned int arraySize, bool (* compare)(Type firstComparedItem, Type secondCompared));
	void printArraay();
	~Solution();
};

