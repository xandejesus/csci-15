/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : rectangle
 * @created     : Tuesday Nov 19, 2019 13:37:54 PST
 */

#include "rectangle.h"

Rectangle::Rectangle()
{
	A = Point(0,0);
	B = Point(0,0);
	C = Point(0,0);
	D = Point(0,0);
}

Rectangle::Rectangle(Point a, Point b, Point c, Point d)
{
	A = Point(a.getX(), a.getY());
	B = Point(b.getX(), b.getY());
	C = Point(c.getX(), c.getY());
	D = Point(d.getX(), d.getY());
	Validate();
}

void Rectangle::Validate()
{
	Parallelogram::Validate();
	if(!(Equals(A.Slope(D), undefined) && A.Slope(B) == 0) && 
			!Equals(A.Slope(B) * A.Slope(D), -1))
	{
		cout << "Slope is not undefined: changing c and d values." << endl;
		C.setAll(B.getX(),C.getY());
		D.setAll(A.getX(),D.getY());
	}
}

void Rectangle::setAll(Point a, Point b, Point c, Point d)
{
	A.setAll(a.getX(), a.getY());
	B.setAll(b.getX(), b.getY());
	C.setAll(c.getX(), c.getY());
	D.setAll(d.getX(), d.getY());
	Validate();
}

void Rectangle::print(ostream& out)
{	
	out << "Rectangle" << endl;
	Parallelogram::print(out);
	return;
}

ostream &operator << (ostream &out, Rectangle a)
{
	a.print(out);
	return out;
}

void Rectangle::read(istream &in)
{
	Point a, b, c, d;
	char garbage;
	double x, y;
	in >> garbage >> x >> garbage >> y;
	a.setAll(x,y);
	in >> garbage >> garbage >> x >> garbage >> y;
	b.setAll(x,y);
	in >> garbage >> garbage >> x >> garbage >> y;
	c.setAll(x,y);
	in >> garbage >> garbage >> x >> garbage >> y;
	d.setAll(x,y);
	in >> garbage;
	setAll(a,b,c,d);
}

istream &operator >> (istream &in, Rectangle &a)
{
	a.read(in);
	return in;
}

double Rectangle::Area()
{
	return A.distance(B) * A.distance(D);
}

double Rectangle::Perimeter()
{
	return Parallelogram::Perimeter();
}
