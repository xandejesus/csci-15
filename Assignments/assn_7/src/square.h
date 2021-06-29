/**
 * @author      : xander (xander@xander-MS-7B49)
 * @file        : square
 * @created     : Sunday Nov 17, 2019 16:54:17 PST
 */

#ifndef SQUARE_H

#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle
{
	protected:
		void Validate();
		void print(ostream &out);
		void read(istream &in);
	public:
		Square();
		Square(Point, Point, Point, Point);
		void setAll(Point, Point, Point, Point);
		double Area();
		double Perimeter();
		friend ostream &operator << (ostream &out, Square a);
		friend istream &operator >> (istream &in, Square &a);
};


#endif /* end of include guard SQUARE_H */

