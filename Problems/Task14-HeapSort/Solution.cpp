#include "stdafx.h"
#include "Solution.h"




template<typename Type>
void Solution<Type>::heapify(unsigned int arraySize, int currentPosition)
{
	int leftSon= leftSonPosition(currentPosition);
	int rightSon = rightSonPosition(currentPosition);
	int comparedItemPosition = currentPosition;
	if (leftSon < arraySize && !compareFunction(itemArray_[currentPosition], itemArray_[leftSon]))
		comparedItemPosition = leftSon;

	if (rightSon < arraySize && !compareFunction(itemArray_[comparedItemPosition], itemArray_[rightSon]))
		comparedItemPosition = rightSon;

	if (currentPosition != comparedItemPosition)
	{
		swap(currentPosition, comparedItemPosition);
		heapify(arraySize, comparedItemPosition);
	}
}

template<typename Type>
void Solution<Type>::buildHeap()
{
	for (int iterator = arraySize_ / 2; iterator >= 0; iterator--) 
		heapify(arraySize_, iterator);
	
}

template<typename Type>
void Solution<Type>::fillArray(Type (* getRandomItem)(void))
{
	for (unsigned int iterator = 0; iterator < arraySize_; iterator++)
		itemArray_[iterator] = getRandomItem();
}

template<typename Type>
int Solution<Type>::leftSonPosition(int position)
{
	return position * 2 + 2;
}

template<typename Type>
int Solution<Type>::rightSonPosition(int position)
{
	return position * 2 + 1;
}

template<typename Type>
void Solution<Type>::swap(int firstItemPosition, int secondItemPosition)
{
	Type tempItem = itemArray_[firstItemPosition];
	itemArray_[firstItemPosition] = itemArray_[secondItemPosition];
	itemArray_[secondItemPosition] = tempItem;
}

template<typename Type>
void Solution<Type>::heapSort()
{
	buildHeap();
	int heapSize = arraySize_;
	while (heapSize > 1) 
	{
		swap(0, heapSize - 1);
		heapSize--;
		heapify(heapSize, 0);
	}
}

template<typename Type>
Solution<Type>::Solution(Type * itemArray, unsigned int arraySize, bool(*compare)(Type firstComparedItem, Type secondCompared)) :
	itemArray_(itemArray), arraySize_(arraySize), compareFunction(compare)
{
	
}

template<typename Type>
Solution<Type>::Solution(Type (* getRandomItem)(void), unsigned int arraySize, bool(*compare)(Type firstComparedItem, Type secondCompared)) :
	arraySize_(arraySize), compareFunction(compare)
{
	itemArray_ = new Type[arraySize_];
	fillArray(getRandomItem);
}

template<typename Type>
void Solution<Type>::printArraay()
{
	for (unsigned int iterator = 0; iterator < arraySize_; iterator++)
		std::cout << itemArray_[iterator] << " ";
	std::cout << std::endl;
}


