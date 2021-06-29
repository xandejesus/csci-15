/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-Air.attlocal.net)
 * @file        : test
 * @created     : Monday Nov 25, 2019 13:15:21 PST
 */
//
#include "myarray.h"
#include "twodarray.h"
#include <iostream>
using namespace std;

int pAccess(MyArray **x, int row, int column)
{
	return (*(*(x + row)))[column];
}

void pInitialize(MyArray **&x, int nRows)
{
	delete x;
	x = new MyArray *[nRows];
	for(int c = 0; c < nRows; c++)
	{
		(x[c]) = new MyArray;
	}
	(*(x[5]))[5] = 39;
	cout << pAccess(x,5,5) << endl;
}

MyArray& tArray(MyArray **&x, int c)
{
	return *(x[c]);
}
int main()
{
	TwoDArray poo(10,10);
	MyArray y;
	y[0] = 99;
	y[9] = 99;
	cout << y[9] << endl;
	MyArray **x = new MyArray *[14];
	(x[9]) = &y; 
	pInitialize(x, 14);
	cout << pAccess(x, 5, 5) << endl;
	(x[9]) = &y;
	cout << ((tArray(x, 9)))[9] <<  endl;
	poo[9][9] = 99;
	cout << poo[10][9] << endl;
	return 0;
}

