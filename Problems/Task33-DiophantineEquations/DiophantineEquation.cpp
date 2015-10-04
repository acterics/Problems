#include "stdafx.h"
#include "DiophantineEquation.h"


std::vector<int> DiophantineEquation::defaultSet(int index)
{
	std::vector<int> defaultSet;
	for (unsigned int iterator = 0; iterator < variablesAmount_; iterator++)
	{
		if (iterator != index)
			defaultSet.push_back(0);
		else
			defaultSet.push_back(1);
	}
	return defaultSet;
}

void DiophantineEquation::initDefaultSets()
{
	for (unsigned int iterator = 0; iterator < variablesAmount_; iterator++)
		factorSets_.push_back(defaultSet(iterator));
}

void DiophantineEquation::initUndefinedResult()
{
	for (unsigned int iterator = 0; iterator > variablesAmount_; iterator++)
		resultVector_.push_back(NAN);
}

void DiophantineEquation::calculateVariablesSets(std::vector<int>& firstSet, std::vector<int>& secondSet, int integerPart)
{
	int tempValue;
	for (unsigned int iterator = 0; iterator < variablesAmount_; iterator++)
	{
		tempValue = secondSet[iterator];
		secondSet[iterator] = firstSet[iterator] - integerPart * secondSet[iterator];
		firstSet[iterator] = tempValue;		
	}
}

int DiophantineEquation::greatestCommonDivisor(int firstArgumentIndex, int secondArgumentIndex)
{
	int firstArgument = factors_[firstArgumentIndex];
	int secondArgument = factors_[secondArgumentIndex];
	int integerPart;
	int tempValue;
	while (secondArgument != 0)
	{
		tempValue = secondArgument;
		integerPart = firstArgument / secondArgument;
		secondArgument = firstArgument % secondArgument;
		calculateVariablesSets(factorSets_[firstArgumentIndex], factorSets_[secondArgumentIndex], integerPart);
		firstArgument = tempValue;
	}
	factors_[firstArgumentIndex] = firstArgument;
	factors_[secondArgumentIndex] = secondArgument;
	return firstArgument;
}

void DiophantineEquation::solveEquation()
{
	for (unsigned int iterator = 1; iterator < variablesAmount_; iterator++)
		greatestCommonDivisor(0, iterator);

	if (freeMember_ % factors_[0] != 0)
	{
		initUndefinedResult();
		hasSolution = false;
		return;
	}
	else
		resultVector_ = factorSets_[0];

	for (unsigned int iterator = 0; iterator < variablesAmount_; iterator++)
		resultVector_[iterator] *= freeMember_ / factors_[0];
}

void DiophantineEquation::printResult()
{
	if (!hasSolution)
	{
		std::cout << "EQUATION HAS NOT SOLUTION" << std::endl;
		return;
	}
	bool zeroGeneralSolution = false;
	for (unsigned int outerIterator = 0; outerIterator < variablesAmount_; outerIterator++)
	{
		std::cout << "x" << outerIterator + 1 << " = ";
		if (resultVector_[outerIterator] == 0)
			zeroGeneralSolution = true;
		else
		{
			std::cout << resultVector_[outerIterator];
			zeroGeneralSolution = false;
		}
		for (unsigned int innerIterator = 1; innerIterator < variablesAmount_; innerIterator++)
		{
			if (factorSets_[innerIterator][outerIterator] != 0)
			{
				if(!zeroGeneralSolution)
					std::cout << " + ";
				if(factorSets_[innerIterator][outerIterator] != 1)
					std::cout << factorSets_[innerIterator][outerIterator] << " * ";
				std::cout << "t" << innerIterator;
			}
		}
		std::cout << ";" << std::endl;
	}
}

DiophantineEquation::DiophantineEquation(std::string filePath)
{

}

DiophantineEquation::DiophantineEquation(std::vector<int> factors, int freeMember)
{
	factors_ = factors;
	freeMember_ = freeMember;
	variablesAmount_ = factors_.size();
	hasSolution = true;
	initDefaultSets();
}


DiophantineEquation::~DiophantineEquation()
{
}
