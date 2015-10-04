#pragma once

#define DEFAULT_RANDOM_VALUE_ACCURACY 1000
#define DEFAULT_STEPS_AMOUNT 10000
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <ctime>


class Solution
{
private:
	double(*function_)(double, double);
	double firstUpperBound_;
	double firstLowerBound_;
	double(*secondUpperBound_)(double argument);
	double secondLowerBound_;
	double measure();
	double getRandomValue(int accuracy);
public:
	Solution(double(*function)(double, double), double(*secondUpperBound)(double),
		double firstLowerBound = 0.5, double firstUpperBound = 1, double secondLowerBound = 0);
	double solve(int stepsAmount = DEFAULT_STEPS_AMOUNT, int randomAccuracy = DEFAULT_RANDOM_VALUE_ACCURACY);
	static double defaultFunction(double firstArgument, double secondArgument);
	static double defaultSecondUpperBound(double argument);
	~Solution();
};

