// Task29-SolvingExpressions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Expression.h"

#define DEFAULT_PATH "InputFile.txt"

int main()
{
	Expression ex(DEFAULT_PATH);
	ex.print();
	std::cout << "RESULT = " << ex.calculateExpression() << std::endl;
    return 0;
}

