#include "stdafx.h"
#include "Solution.h"




template<typename Type>
void Solution<Type>::convertArray(unsigned int arraySize, int limitValue)
{
	//int T = itemArray_[arraySize - 1];

	//while (arraySize <= limitValue / 2) {

	//	int j = arraySize + arraySize;

	//	if ((j < limitValue) && (itemArray_[j - 1] < itemArray_[j])) j++;

	//	if (T >= itemArray_[j - 1]) {

	//		break;

	//	}
	//	else { 	

	//		itemArray_[arraySize - 1] = itemArray_[j - 1];
	//		arraySize = j;
	//	}
	//}

	//itemArray_[arraySize - 1] = T;








	if (arraySize == 1)
		return;
	int indexOfCorrectItem;
	Type tempItem;
	for (int outerIterator = limitValue; outerIterator >= 0; outerIterator--)
	{
		unsigned int innerIterator = outerIterator;
		while (innerIterator * 2 + 1 > arraySize)
		{
			if (innerIterator * 2 + 1 == arraySize - 1)
				indexOfCorrectItem = innerIterator * 2 + 1;
			else if (compareFunction(itemArray_[innerIterator * 2 + 1], itemArray_[innerIterator * 2 + 2]))
				indexOfCorrectItem = innerIterator * 2 + 1;
			else
				indexOfCorrectItem = innerIterator * 2 + 2;

			if (!compareFunction(itemArray_[innerIterator], itemArray_[indexOfCorrectItem]))
			{
				tempItem = itemArray_[innerIterator];
				itemArray_[innerIterator] = itemArray_[indexOfCorrectItem];
				itemArray_[indexOfCorrectItem] = tempItem;
				innerIterator = indexOfCorrectItem;
			}
			else
				break;
		}
	}
	tempItem = itemArray_[limitValue];
	itemArray_[limitValue] = itemArray_[arraySize - 1];
	itemArray_[arraySize - 1] = tempItem;
	convertArray(arraySize - 1, 1);


}

template<typename Type>
void Solution<Type>::fillArray(Type (* getRandomItem)(void))
{
	for (unsigned int iterator = 0; iterator < arraySize_; iterator++)
		itemArray_[iterator] = getRandomItem();
}

template<typename Type>
void Solution<Type>::heapSort()
{
	int N = arraySize_;
	for (int k = N / 2; k > 0; k--) convertArray(k, N);

	do {

		int T = itemArray_[0];
		itemArray_[0] = itemArray_[N - 1];
		itemArray_[N - 1] = T;

		N--;
		convertArray(1, N);

	} while (N > 1);

	//convertArray(arraySize_, arraySize_ / 2);
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


