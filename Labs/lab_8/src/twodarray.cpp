/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-Air.attlocal.net)
 * @file        : twodarray
 * @created     : Monday Nov 25, 2019 16:51:14 PST
 */

#include "twodarray.h"

TwoDArray::TwoDArray()
{
	nRows = 10;
	nCols = 10;
	array = new MyArray *[10];
	for(int cont = 0; cont < 10; cont++)
	{
		(array[cont]) = new MyArray;
	}
}

TwoDArray::TwoDArray(int rows, int columns)
{
	nRows = rows;
	nCols = columns;
	array = new MyArray *[rows];
	for(int cont = 0; cont < 10; cont++)
	{
		(array[cont]) = new MyArray(columns);
	}

}

MyArray &TwoDArray::operator [](int row)
{
	if(row >= nRows)
	{
		cout << "index greater than nRows, returning base" << endl;
		return *(array[0]);
	}
	return *(array[row]);
}

