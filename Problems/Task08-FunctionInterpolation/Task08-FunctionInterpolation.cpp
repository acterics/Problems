// Task08-FunctionInterpolation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CubicSpline.h"

#define DEFAULT_PATH "resourceFile.txt"

int main()
{
	CubicSpline cubicSpline(DEFAULT_PATH);
	std::cout << "f(2.5) = " << cubicSpline.interpolate(2.5) << std::endl;

    return 0;
}

