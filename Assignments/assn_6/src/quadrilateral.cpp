/**
 * @author      : xander (xander@xander-MS-7B49)
 * @file        : quadrilateral
 * @created     : Sunday Nov 17, 2019 11:47:54 PST
 */

#include "quadrilateral.h"
using std::ostream;
using std::istream;
Quadrilateral::Quadrilateral()
{
	A = Point(0,0);
	B = Point(0,0);
	C = Point(0,0);
	D = Point(0,0);
}

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d)
{
	A = Point(a.getX(), a.getY());
	B = Point(b.getX(), b.getY());
	C = Point(c.getX(), c.getY());
	D = Point(d.getX(), d.getY());
	Validate();
}

Point Quadrilateral::getA()
{
	return A;
}

Point Quadrilateral::getB()
{
	return B;
}

Point Quadrilateral::getC()
{
	return C;
}

Point Quadrilateral::getD()
{
	return D;
}

void Quadrilateral::setAll(Point a, Point b, Point c, Point d)
{
	A.setAll(a.getX(), a.getY());
	B.setAll(b.getX(), b.getY());
	C.setAll(c.getX(), c.getY());
	D.setAll(d.getX(), d.getY());
	Validate();
}

double Quadrilateral::Area()
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

double Quadrilateral::Perimeter() 
{
	return A.distance(B) * 2 + A.distance(D) * 2;
}

ostream &operator << (ostream &out, Quadrilateral &a)
{
	a.print(out);
	return out;
}

void Quadrilateral::Validate()
{
	if(A.getX() > B.getX() || D.getX() > C.getX() ||A.getY() > C.getY() 
			|| A.getY() > D.getY())
	{
		cout << "Improper order for Quadrilateral" << endl;
		A.setAll(0,0);
		B.setAll(5,0);
		C.setAll(5,5);
		D.setAll(2,3);
	}	
	return;
}

istream &operator >>(istream &in, Quadrilateral &a)
{
	a.read(in);
	return in;
}

void Quadrilateral::read(istream &in)
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

void Quadrilateral::print(ostream &out)
{
	out << "Quadrilateral" << endl;
	out << "A: " << getA()  
		<< "B: " << getB()
		<< "C: " << getC()
		<< "D: " << getD() << flush;
}
