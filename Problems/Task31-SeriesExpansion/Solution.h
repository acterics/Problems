#pragma once
#include <math.h>
#include <cmath>
#define M_PI 3.14159265358979323846 
#define DEFAULT_ACCURACY 0.00001
class Solution
{
private:
	double accuracy_;
public:
	Solution(double accuracy);
	~Solution();
	double solve(double argument);

};

