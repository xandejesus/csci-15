//
// calculator.cpp
//
// xander de jesus 
// 10 - 21 - 2019 
// CSCI-15 class assignment
// This program does cool things with classes


#include "rational.h"
#include <iostream>
#include <fstream>
using namespace std;
// ~~~~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Specify an input and an output file" << endl;
		return -1;
	}
	ifstream input;
	input.open(argv[1]);
	if(!input)
	{
		cout << "Error opening input file." << endl;
		return -5;
	}
	ofstream output;
	output.open(argv[2]);
	RATIONAL lhs;
	RATIONAL rhs;
	RATIONAL answer;
	char oper;
	char garb;
	while(!input.eof())
	{
		input >> lhs;
		input >> oper;
		input >> rhs;
		switch (oper)
		{
			case '+':
				answer = lhs + rhs;
				break;
			case '-':
				answer = lhs - rhs;
				break;
			case '/':
				answer = lhs / rhs;
				break;
			case '*':
				answer = lhs * rhs;
				break;
		}
		if(input.eof())
			break;
		output << answer << endl;		
	}
}

