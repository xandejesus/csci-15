/**
 * @author      : xander (xander@xander-MS-7B49)
 * @file        : test
 * @created     : Sunday Nov 17, 2019 12:02:54 PST
 */
// assn_6.cpp
//
// Xander de Jesus (with Keith Mehl Aggregation)
// 11 - 20 - 2019
// CSCI-15 Inheritance Assignment 6
// This program takes a bunch of shapes and inherits them with an inheritance
// chain of sorts. It makes sense after reading through all of this code.
#include "point.h"
#include "square.h"
#include <fstream>



int main(int argc, char * argv[])
{
	if(argc != 3)
	{
		cout << "Please enter in an input and output file name." << endl;
		return -1;
	}
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	if(!input || !output)
	{
		cout << "Error opening input / output. Goodbye" << endl;
		return -1;
	}
	Parallelogram p;
	Quadrilateral q;
	Trapezoid t;
	Square s;
	Rectangle r;
	char x = 'r';
	while(!input.eof())
	{
		input >> x;
		if(input.eof())
			break;
		switch(x)
		{
			case 't':
				input >> t;
				output << t << endl;
				output << t.Area() << endl;
				output << t.Perimeter() << endl;
				break;
			case 'r':
				input >> r;
				output << r << endl;
				output << r.Area() << endl;
				output << r.Perimeter() << endl;
				break;
			case 's':
				input >> s;
				output << s << endl;
				output << s.Area() << endl;
				output << s.Perimeter() << endl;
				break;
			case 'p':
				input >> p;
				output << p << endl;
				output << p.Area() << endl;
				output << p.Perimeter() << endl;
				break;
			case 'q':
				input >> q;
				output << q << endl;
				output << q.Area() << endl;
				output << q.Perimeter() << endl;
				break;
		}
		output << "~~~~~~~~~~~~~~~~~~~~" << endl;
	}
	input.close();
	output.close();
}

