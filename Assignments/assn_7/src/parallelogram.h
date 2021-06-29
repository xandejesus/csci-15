/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : parallelogram
 * @created     : Friday Nov 15, 2019 12:28:36 PST
 */

#ifndef PARALLELOGRAM_H

#define PARALLELOGRAM_H

#include "trapezoid.h"
#include <iostream>
using namespace std;
class Parallelogram : public Trapezoid
{
	protected:
		void Validate();
		void read(istream&);
		void print(ostream&);
	public:
		Parallelogram();
		Parallelogram(Point, Point, Point, Point);
		double Area();
		double Perimeter();
		void setAll(Point, Point, Point, Point);
		friend ostream& operator << (ostream& out, Parallelogram a);
		friend istream& operator >> (istream& in, Parallelogram &a);
};


#endif /* end of include guard PARALLELOGRAM_H */

