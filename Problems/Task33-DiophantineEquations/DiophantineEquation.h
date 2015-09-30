#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <cmath>


class DiophantineEquation
{
private:
	unsigned int variablesAmount_;
	std::vector<int> factors_;
	std::vector<int> resultVector_;
	std::vector<std::vector<int> > factorSets_;
	int freeMember_;
	bool hasSolution;

	std::vector<int> defaultSet(int index);
	void initDefaultSets();
	void initUndefinedResult();
	void calculateVariablesSets(std::vector<int> &firstSet, std::vector<int> &secondSet, int integerPart);
	int greatestCommonDivisor(int firstArgument, int secondArgument);
public:
	void solveEquation();
	void printResult();
	DiophantineEquation(std::string filePath);
	DiophantineEquation(std::vector<int> factors, int freeMember);
	~DiophantineEquation();
};

