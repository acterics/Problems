// Task13-TabularMaximumSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solution.h"

int main()
{
	Solution* s = new Solution("ResourceFile.txt");
	s->printTable();
	s->solve();
	s->printResult();
    return 0;
}

