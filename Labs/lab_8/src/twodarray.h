/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-Air.attlocal.net)
 * @file        : twodarray
 * @created     : Monday Nov 25, 2019 16:47:13 PST
 */

#ifndef TWODARRAY_H

#define TWODARRAY_H
#include "myarray.h"

class TwoDArray
{
	private:
		int nRows;
		int nCols;
		MyArray **array;
	public:
		TwoDArray();
		TwoDArray(int row, int col);
		MyArray& operator [](int i);

};


#endif /* end of include guard TWODARRAY_H */

