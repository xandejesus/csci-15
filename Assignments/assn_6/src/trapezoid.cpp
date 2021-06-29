/**
 * @author      : xander (xander@xander-MS-7B49)
 * @file        : trapezoid
 * @created     : Sunday Nov 17, 2019 17:56:56 PST
 */

#include "trapezoid.h"

Trapezoid::Trapezoid()
{
   A = Point(0,0);
   B = Point(0,0);
   C = Point(0,0);
   D = Point(0,0); 
}

Trapezoid::Trapezoid(Point a, Point b, Point c, Point d)
{
	A = Point(a.getX(), a.getY());
	D = Point(d.getX(), d.getY());
	C = Point(c.getX(), c.getY());
	B = Point(b.getX(), b.getY());
}
void Trapezoid::setAll(Point a, Point b, Point c, Point d)
{
	A.setAll(a.getX(), a.getY());
	B.setAll(b.getX(), b.getY());
	C.setAll(c.getX(), c.getY());
	D.setAll(d.getX(), d.getY());
	Validate();
}

double Trapezoid::Area()
{
	return A.distance(B) + C.distance(D) * C.distance(B) / 2;
}

double Trapezoid::Perimeter()
{
	return Quadrilateral::Perimeter();
}
void Trapezoid::Validate()
{
	Quadrilateral::Validate();
	if(!Equals(A.Slope(B), D.Slope(C)))
	{
		cout << "Trapezoid: Top Slope and base slope not equal, changing points" << endl;
		A.setAll(0,0);
		B.setAll(4,0);
		C.setAll(2,4);
		D.setAll(0,4);
	}

}

istream &operator >> (istream &in, Trapezoid &t)
{
	t.read(in);
	return in;
}

ostream &operator << (ostream &out, Trapezoid t)
{
	t.print(out);
	return out;
}

void Trapezoid::print(ostream &out)
{
	out << "Trapezoid" << endl;
	Quadrilateral::print(out);
}

void Trapezoid::read(istream &in)
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
