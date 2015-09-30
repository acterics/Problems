// Task29-SolvingExpressions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Expression.h"

#define DEFAULT_PATH "InputFile.txt"

int main()
{
	Expression ex(DEFAULT_PATH);
	Expression test1("test1.txt");
	Expression test2("test2.txt");
	Expression test3("test3.txt");
	ex.print();
	std::cout << "RESULT = " << ex.calculateExpression() << std::endl;
	test1.print();
	std::cout << "RESULT = " << test1.calculateExpression() << std::endl;
	test2.print();
	std::cout << "RESULT = " << test2.calculateExpression() << std::endl;
	test3.print();
	std::cout << "RESULT = " << test3.calculateExpression() << std::endl;
    return 0;
}

