#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <stack>
#include <iostream>

class Expression :
	public std::vector<std::string>
{
private:
	void parseString(std::string inputString);
	
public:
	


	Expression(std::string filePath);

	~Expression();
	void clearExpressionFromSpaces(std::string &inputString);
	bool isSymbol(char inputChar);
	bool isNumber(char inputChar);
	std::string scanOperator(std::string inputString, int currentPosition);
	int operatorPriority(std::string inputOperator);

	void print();
};

