/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : square
 * @created     : Tuesday Nov 19, 2019 14:06:19 PST
 */

#include "square.h"

Square::Square()
{
    A = Point(0,0);
	B = Point(0,0);
	C = Point(0,0);
	D = Point(0,0);
}

Square::Square(Point a, Point b, Point c, Point d)
{
	A = a;
	B = b;
	C = c;
	D = d;
}

void Square::setAll(Point a, Point b, Point c, Point d)
{
	A.setAll(a.getX(), a.getY());
	B.setAll(b.getX(), b.getY());
	C.setAll(c.getX(), c.getY());
	D.setAll(d.getX(), d.getY());
	Validate();
	return;
}

void Square::Validate()
{
	Rectangle::Validate();
	if(!Equals(A.distance(B), A.distance(D)))
	{
		cout << "Not square Dimensions, changing stuff" << endl;
		C.setAll(C.getX(), C.getY() + A.distance(B) - A.distance(D));
		D.setAll(A.getX(), D.getY() + A.distance(B) - A.distance(D));
	}
	return;
}

void Square::print(ostream &out)
{
	out << "Square" << endl;
	Rectangle::print(out);
	return;
}

void Square::read(istream &in)
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

istream &operator >> (istream &in, Square &a)
{
	a.read(in);
	return in;
}

ostream &operator << (ostream &out, Square a)
{
	a.print(out);
	return out;
}

double Square::Area()
{
	return A.distance(B) * A.distance(D);
}

double Square::Perimeter()
{
	return A.distance(B) * 4;
}
