/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : trapezoid
 * @created     : Friday Nov 15, 2019 12:16:53 PST
 */

#ifndef TRAPEZOID_H

#define TRAPEZOID_H

#include "quadrilateral.h"

class Trapezoid : public Quadrilateral
{
	protected:
		void Validate();
		void print(ostream &out);
		void read(istream& in);
	public:
		Trapezoid();
		Trapezoid(Point, Point, Point, Point);
		void setAll(Point, Point, Point, Point);
		double Area();
		double Perimeter();
		friend ostream& operator << (ostream &out, Trapezoid t);
		friend istream& operator >> (istream &in, Trapezoid &t);
};


#endif /* end of include guard TRAPEZOID_H */

