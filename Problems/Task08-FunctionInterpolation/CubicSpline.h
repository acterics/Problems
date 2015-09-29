#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
class CubicSpline
{
private:
	struct SplineTuple
	{
		double freeMember,
			firstFactor,
			secondFactor,
			thirdFactor,
			argumentValue;
	};

	std::vector<SplineTuple> splines_;


	SplineTuple emptySpline();
	double argumentDifference(int index);
	void tridiagonalMatrixAlgorithm();
	double stringToNumber(std::string inputString);
public:
	void printSplines();
	void printSpline(unsigned int index);
	CubicSpline(std::string filePath);
	double interpolate(double argument);
	~CubicSpline();
};

