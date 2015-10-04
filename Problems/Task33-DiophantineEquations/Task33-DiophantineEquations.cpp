// Task33-DiophantineEquations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DiophantineEquation.h"

int main()
{
	DiophantineEquation de({ 6, 24, 322 }, 1234);
	de.solveEquation();
	de.printResult();
    return 0;
}

