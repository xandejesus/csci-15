#include "DATE.h"
#include <iostream>
#include <fstream>
using namespace std;
int dateCalc(DATE d, DATE d1);
int main()
{
	DATE d1;
	DATE d2(1, 1, 2019);
	DATE d3(1, 3, 2019);
	int n = d2.Difference(d3);
	cout << n << endl;
}
