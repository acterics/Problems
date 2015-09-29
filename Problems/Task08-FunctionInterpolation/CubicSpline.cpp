#include "stdafx.h"
#include "CubicSpline.h"





CubicSpline::SplineTuple CubicSpline::emptySpline()
{
	SplineTuple spline;
	spline.firstFactor = 0;
	spline.secondFactor = 0;
	spline.thirdFactor = 0;
	spline.freeMember = 0;
	spline.argumentValue = 0;
	return spline;
}

double CubicSpline::argumentDifference(int index)
{
	return splines_[index].argumentValue - splines_[index - 1].argumentValue;
}

void CubicSpline::tridiagonalMatrixAlgorithm()
{
	std::vector<double> firstPassCoefficients;
	std::vector<double> secondPassCoefficients;
	std::vector<double> tempFactors = { 0, 0, 0 ,0 ,0 };

	firstPassCoefficients.push_back(0);
	secondPassCoefficients.push_back(0);
	for (unsigned int iterator = 1; iterator < splines_.size() - 1; iterator++)
	{
		tempFactors[0] = argumentDifference(iterator);
		tempFactors[1] = argumentDifference(iterator + 1);
		tempFactors[2] = 2 * (tempFactors[0] + tempFactors[1]);
		tempFactors[3] = 3 * (((splines_[iterator + 1].freeMember - splines_[iterator].freeMember) /
						 tempFactors[1] - ((splines_[iterator].freeMember - splines_[iterator - 1].freeMember) / tempFactors[0])));
		tempFactors[4] = (tempFactors[0] * firstPassCoefficients[iterator - 1] + tempFactors[2]);

		firstPassCoefficients.push_back(-tempFactors[1] / tempFactors[4]);
		secondPassCoefficients.push_back((tempFactors[3] - tempFactors[0] * secondPassCoefficients[iterator - 1]) / tempFactors[4]);

	}

	splines_[splines_.size() - 1].secondFactor = (tempFactors[3] - tempFactors[0] * secondPassCoefficients[splines_.size() - 2]) /
												(tempFactors[2] + tempFactors[1] * firstPassCoefficients[splines_.size() - 2]);

	for (int iterator = splines_.size() - 2; iterator >= 0; iterator--)
		splines_[iterator].secondFactor = firstPassCoefficients[iterator] * splines_[iterator + 1].secondFactor + secondPassCoefficients[iterator];

	firstPassCoefficients.clear();
	secondPassCoefficients.clear();
	tempFactors.clear();
}

void CubicSpline::printSplines()
{
	for (unsigned int iterator = 0; iterator < splines_.size(); iterator++)
		printSpline(iterator);
}

void CubicSpline::printSpline(unsigned int index)
{
	std::cout << "S" << index << "(x) = " <<
		splines_[index].freeMember << " + " <<
		splines_[index].firstFactor << " * (x - " << splines_[index].argumentValue << ") + (" <<
		splines_[index].secondFactor << "/2) * (x - " << splines_[index].argumentValue << ")^2 + (" <<
		splines_[index].thirdFactor << "/6) * (x - " << splines_[index].argumentValue << ")^3" << std::endl;
}

CubicSpline::CubicSpline(std::string filePath)
{
	std::ifstream inputStream(filePath, std::ios::in);
	std::string inputArguments;
	std::string inputResults;
	getline(inputStream, inputArguments);
	getline(inputStream, inputResults);
	inputStream.close();
	for (unsigned int argumentIterator = 0, splineIterator = 0; argumentIterator < inputArguments.length(); argumentIterator++)
	{
		if (inputArguments[argumentIterator] == ' ' || argumentIterator == inputArguments.length() - 1)
		{
			splines_.push_back(emptySpline());
			splines_[splineIterator].argumentValue = stringToNumber(inputArguments.substr(0, argumentIterator));
			splineIterator++;
			inputArguments = inputArguments.substr(argumentIterator + 1);
			argumentIterator = 0;
		}
	}
	for (unsigned int resultIterator = 0, splineIterator = 0; resultIterator < inputResults.length(); resultIterator++)
	{
		if (inputResults[resultIterator] == ' ' || resultIterator == inputResults.length() - 1)
		{
			splines_[splineIterator].freeMember = stringToNumber(inputResults.substr(0, resultIterator));
			splineIterator++;
			inputResults = inputResults.substr(resultIterator + 1);
			resultIterator = 0;
		}
	}
	splines_[0].secondFactor = 0;

	tridiagonalMatrixAlgorithm();

	for (unsigned int iterator = splines_.size() - 1; iterator > 0; iterator--)
	{
		splines_[iterator].thirdFactor = (splines_[iterator].secondFactor - splines_[iterator - 1].secondFactor) / argumentDifference(iterator);

		splines_[iterator].firstFactor = argumentDifference(iterator) * (2 * splines_[iterator].secondFactor + splines_[iterator - 1].secondFactor) / 6 + 
										(splines_[iterator].freeMember - splines_[iterator - 1].freeMember) / argumentDifference(iterator);
	}

}

double CubicSpline::interpolate(double argument)
{
	unsigned int currentSplineIndex;
	if (argument <= splines_[0].argumentValue)
		currentSplineIndex = 0;
	else if (argument >= splines_[splines_.size() - 1].argumentValue)
		currentSplineIndex = splines_.size() - 1;
	else
	{
		unsigned int topMeasure = splines_.size() - 1,
					bottomMeasure = 0;
		while (bottomMeasure + 1 < topMeasure)
		{
			unsigned int middleValue = bottomMeasure + (topMeasure - bottomMeasure) / 2;
			if (argument <= splines_[middleValue].argumentValue)
				topMeasure = middleValue;
			else
				bottomMeasure = middleValue;
		}
		currentSplineIndex = topMeasure;
	}
	double difference = argument - splines_[currentSplineIndex].argumentValue;


	return splines_[currentSplineIndex].freeMember +
		(splines_[currentSplineIndex].firstFactor +
		(splines_[currentSplineIndex].secondFactor / 2 + splines_[currentSplineIndex].thirdFactor * difference / 6) * difference) * difference;
}

double CubicSpline::stringToNumber(std::string inputString)
{
	double resultNumber;
	std::istringstream convertingStream(inputString);
	convertingStream >> resultNumber;
	return resultNumber;
}

CubicSpline::~CubicSpline()
{
}
