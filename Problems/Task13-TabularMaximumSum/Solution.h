#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Solution
{
private:
	std::vector<std::vector<int> > table_;
	unsigned int columnSize_;
	unsigned int rowSize_;
	int topColumnCoordinate_;
	int topRowCoordinate_;
	int bottomColumnCoordinate_;
	int bottomRowCoordinate_;
	int stringToInteger(std::string inputString);
	int rectangleSum(int topRowCoordinate, int topColumnCoordinate, int bottomRowCoordinate, int bottomColumnCoordinate);
	std::vector<int> parseString(std::string inputString);
public:
	Solution(std::string filePath);
	void solve();
	void printTable();
	void printResult();
	~Solution();
};

