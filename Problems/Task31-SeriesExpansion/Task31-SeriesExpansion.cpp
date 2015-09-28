// Task31-SeriesExpansion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"
#include <iostream>


int main()
{
	Solution solution(DEFAULT_ACCURACY);
	std::cout << "cos(pi/3) = " << solution.solve(M_PI / 3) << ", " << cos(M_PI / 3) << std::endl;
	std::cout << "cos(-7pi/3) = " << solution.solve(-7 * M_PI / 3) << ", " << cos(-7 * M_PI / 3) << std::endl;
	std::cout << "cos(4*pi/13) = " << solution.solve(4 * M_PI / 13) << ", " << cos(4 * M_PI / 13) << std::endl;
	std::cout << "cos(2*pi/3) = " << solution.solve(2 * M_PI / 3) << ", " << cos(2 * M_PI / 3) << std::endl;
	std::cout << "cos(pi/6) = " << solution.solve(M_PI / 6) << ", " << cos(M_PI / 6) << std::endl;
	std::cout << "cos(pi/2) = " << solution.solve(M_PI / 2) << ", " << cos(M_PI / 2) << std::endl;
	std::cout << "cos(0) = " << solution.solve(0) << ", " << cos(0) << std::endl;
    return 0;
}

