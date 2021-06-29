/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : quadrilateral
 * @created     : Friday Nov 15, 2019 09:56:24 PST
 */

#ifndef QUADRILATERAL_H

#define QUADRILATERAL_H
#include "point.h"
#include <iostream>
#include <cmath>

class Quadrilateral{
	protected:
		Point A;
		Point B;
		Point C;
		Point D;
		void Validate();
		virtual void print(ostream &out);
		virtual void read(istream &in);
	public:
		Quadrilateral();
		Quadrilateral(Point a, Point b, Point c, Point d);
		Point getA();
		Point getB();
		Point getC();
		Point getD();
		void setAll(Point a, Point b, Point c, Point d);
		virtual double Area();
		virtual double Perimeter();
		friend ostream &operator << (ostream &out, Quadrilateral &a);
		friend istream &operator >> (istream &in, Quadrilateral &a);
};


#endif /* end of include guard QUADRILATERAL_H */

