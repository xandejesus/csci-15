/**
 * @author      : xander (xander@xander-MS-7B49)
 * @file        : parallelogram
 * @created     : Sunday Nov 17, 2019 20:25:38 PST
 */

#include "parallelogram.h"

Parallelogram::Parallelogram()
{
    A = Point(0,0);
	B = Point(0,0);
	C = Point(0,0);
	D = Point(0,0);
}

Parallelogram::Parallelogram(Point a, Point b, Point c, Point d)
{
	A = Point(a.getX(), a.getY());
	B = Point(b.getX(), b.getY());
	C = Point(c.getX(), c.getY());
	D = Point(d.getX(), d.getY());
	Validate();
}
void Parallelogram::setAll(Point a, Point b, Point c, Point d)
{
	A.setAll(a.getX(), a.getY());
	B.setAll(b.getX(), b.getY());
	C.setAll(c.getX(), c.getY());
	D.setAll(d.getX(), d.getY());
	Validate();
}
void Parallelogram::Validate()
{
	Trapezoid::Validate();
	if(!Equals(D.Slope(A), C.Slope(B)))
	{
		cout << A << B << C << D << endl;
		cout << D.Slope(A) << " " << C.Slope(B) << endl;
		cout << "Side sides are not parallel: Parallelogram" << endl;
		A.setAll(0,0);
		B.setAll(4,0);
		C.setAll(6,2);
		D.setAll(2,2);
	}
}

void Parallelogram::read(istream &in)
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

istream& operator >> (istream &in, Parallelogram &a)
{
	a.read(in);
	return in;
}

void Parallelogram::print(ostream& out)
{
	out << "Parallelogram" << endl;
	Trapezoid::print(out);
	return;
}

ostream& operator << (ostream& out, Parallelogram a)
{
	a.print(out);
	return out;
}

double Parallelogram::Perimeter()
{
	return 2 * A.distance(B) + 2 * A.distance(D);
}

double Parallelogram::Area()
{
	double p = (A.distance(B) + C.distance(A) + C.distance(B)) / 2;
	cout << p << endl;
	double t1 = sqrt(p * (p - A.distance(B)) * 
				(p - B.distance(C)) * (p - C.distance(A)));
	p = (A.distance(D) + A.distance(C) + D.distance(C)) / 2;
	cout << p << endl;
	double t2 = sqrt(p * (p - D.distance(A)) * 
			(p - C.distance(D)) * (p - C.distance(A)));
	return t1 + t2;

}
