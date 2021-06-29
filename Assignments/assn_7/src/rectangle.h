/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : rectangle
 * @created     : Friday Nov 15, 2019 12:31:28 PST
 */

#ifndef RECTANGLE_H

#define RECTANGLE_H

#include "parallelogram.h"

class Rectangle : public Parallelogram
{
	protected:
		void Validate();
		void read(istream &in);
		void print(ostream &out);
	public:
		Rectangle();
		Rectangle(Point, Point, Point, Point);
		void setAll(Point, Point, Point, Point);
		double Area();
		double Perimeter();
		friend ostream& operator << (ostream &out, Rectangle a);
		friend istream& operator >> (istream &in, Rectangle &a);
};


#endif /* end of include guard RECTANGLE_H */

