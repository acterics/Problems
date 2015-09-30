// Task33-DiophantineEquations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DiophantineEquation.h"

int main()
{
	DiophantineEquation de({ 18, 42, 10 }, 13);
	de.solveEquation();
	de.printResult();
    return 0;
}

