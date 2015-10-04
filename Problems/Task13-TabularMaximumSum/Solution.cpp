#include "stdafx.h"
#include "Solution.h"



int Solution::stringToInteger(std::string inputString)
{
	int resultNumber;
	std::istringstream convertingStream(inputString);
	convertingStream >> resultNumber;
	return resultNumber;
}

int Solution::rectangleSum(int topRowCoordinate, int topColumnCoordinate, int bottomRowCoordinate, int bottomColumnCoordinate)
{
	return table_[topRowCoordinate][topColumnCoordinate] + table_[topRowCoordinate][bottomColumnCoordinate] +
		table_[bottomRowCoordinate][bottomColumnCoordinate] + table_[bottomRowCoordinate][topColumnCoordinate];
}

std::vector<int> Solution::parseString(std::string inputString)
{
	std::vector<int> resultVector;
	for (unsigned int iterator = 0; iterator < inputString.length();)
	{
		if (iterator == inputString.length() - 1)
			resultVector.push_back(stringToInteger(inputString));
		if (inputString[iterator] == ' ')
		{
			resultVector.push_back(stringToInteger(inputString.substr(0, iterator)));
			inputString = inputString.substr(iterator + 1);
			iterator = 0;
		}
		else
			iterator++;
	}
	return resultVector;
}
Solution::Solution(std::string filePath)
{
	std::ifstream inputStream(filePath, std::ios::in);
	std::string tempString;
	getline(inputStream, tempString);
	while (!tempString.empty())
	{
		table_.push_back(parseString(tempString));
		tempString.clear();
		getline(inputStream, tempString);
	}
	inputStream.close();
	rowSize_ = table_.size();
	columnSize_ = table_[0].size();
	
}

void Solution::solve()
{
	int maximumSum = 0;
	int currentSum;
	for (unsigned int firstPointRowIterator = 0; firstPointRowIterator < rowSize_ - 1; firstPointRowIterator++)
	{
		for (unsigned int firstPointColumnIterator = 0; firstPointColumnIterator < rowSize_ - 1; firstPointColumnIterator++)
		{
			for (unsigned int secondPointRowIterator = firstPointRowIterator + 1; secondPointRowIterator < rowSize_; secondPointRowIterator++)
			{
				for (unsigned int secondPointColumnIterator = firstPointColumnIterator + 1; secondPointColumnIterator < columnSize_; secondPointColumnIterator++)
				{
					currentSum = rectangleSum(firstPointRowIterator, firstPointColumnIterator, secondPointRowIterator, secondPointColumnIterator);
					if (currentSum > maximumSum)
					{
						topRowCoordinate_ = firstPointRowIterator;
						topColumnCoordinate_ = firstPointColumnIterator;
						bottomRowCoordinate_ = secondPointRowIterator;
						bottomColumnCoordinate_ = secondPointColumnIterator;
						maximumSum = currentSum;
					}
				}
			}
		}
	}
}

void Solution::printTable()
{
	for (unsigned int rowIterator = 0; rowIterator < rowSize_; rowIterator++)
	{
		for (unsigned int columnIterator = 0; columnIterator < columnSize_; columnIterator++)
			std::cout << table_[rowIterator][columnIterator] << " ";
		std::cout << std::endl;
	}
}

void Solution::printResult()
{
	std::cout << "(" << topColumnCoordinate_ << ", " << topRowCoordinate_ << ") " << table_[topRowCoordinate_][topColumnCoordinate_] << "; ";
	std::cout << "(" << bottomColumnCoordinate_ << ", " << topRowCoordinate_ << ") " << table_[topRowCoordinate_][bottomColumnCoordinate_] << std::endl;
	std::cout << "(" << topColumnCoordinate_ << ", " << bottomRowCoordinate_  << ") " << table_[bottomRowCoordinate_][topColumnCoordinate_] << "; ";
	std::cout << "(" << bottomColumnCoordinate_ << ", " << bottomRowCoordinate_ << ") " << table_[bottomRowCoordinate_][bottomColumnCoordinate_] << std::endl;
}

Solution::~Solution()
{
}
