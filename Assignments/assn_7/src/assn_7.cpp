/**
 * @author      : xander (xander@xander-MS-7B49)
 * @file        : test
 * @created     : Sunday Dec 1, 2019 12:02:54 PST
 */
// assn_7.cpp
//
// Xander de Jesus (with Keith Mehl Aggregation)
// 12 - 02 - 2019
// CSCI-15 Polymorphism Assignment 7
// This program takes a bunch of shapes and inherits them with an inheritance
// chain of sorts. It makes sense after reading through all of this code.
#include "point.h"
#include "square.h"
#include <fstream>

void printStar (ostream &out, Quadrilateral *a)
{
	out << (*a) << endl;
	out << "Area: " << (*a).Area() << endl;
	out << "Perimeter: " << (*a).Perimeter() << endl;
	out << endl;
}

void printAnd (ostream &out, Quadrilateral &a)
{
	printStar (out, &a);
}

int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		cout << "Specify output file." << endl;
		return -1;
	}
	ofstream output(argv[1]);
	Parallelogram p;
	Quadrilateral q;
	Trapezoid t;
	Square s;//
	Rectangle r;
	Quadrilateral *array[] = {
		&q, &t, &p, &r, &s
	};
	for(int x = 0; x < 5; x++)
	{
		printStar(output, array[x]);
		printStar(output, array[x]);
	}
	output.close();
}

