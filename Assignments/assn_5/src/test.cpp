/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : test
 * @created     : Wednesday Oct 23, 2019 18:55:57 PDT
 */

#include "RATIONAL.h"
#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	ifstream input("test.txt");
	RATIONAL a;
	RATIONAL b;
	char oper, garb;
	while(!input.eof())
	{
		a.isread(input);
		input >> oper;
		b.isread(input);

	}
	cout << oper << endl;
	a.print(cout);
	b.print(cout);
}

