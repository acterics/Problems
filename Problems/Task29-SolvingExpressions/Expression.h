#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <iostream>
#include <sstream>
#include <math.h>

class Expression :
	public std::vector<std::string>
{
private:
	void parseString(std::string inputString);
	
public:
	


	Expression(std::string filePath);

	~Expression();
	std::string calculateExpression();
	void clearExpressionFromSpaces(std::string &inputString);
	bool isSymbol(char inputChar);
	bool isNumber(char inputChar);
	std::string scanOperator(std::string inputString, int currentPosition);
	int operatorPriority(std::string inputOperator);

	void print();
	bool isOperator(std::string inputExpression);
	std::string calculateBinaryOperation(std::string firstStringOperand, std::string secondStringOperand, std::string inputOperator);
	int stringToNumber(std::string inputString);
	std::string numberToString(int inputFloat);
};

