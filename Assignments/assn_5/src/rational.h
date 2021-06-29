#include <iostream>
using namespace std;
#ifndef RATIONAL_H
#define RATIONAL_H
class RATIONAL
{
	private:
		long num, denom;
		void validate();
		void reduce();
	public:
		RATIONAL();
		RATIONAL(long n, long d);
		RATIONAL add(RATIONAL);
		RATIONAL subtract(RATIONAL);
		RATIONAL divide(RATIONAL);
		RATIONAL multiply(RATIONAL);
		void isread(istream &input);
		void print(ostream &output);
		RATIONAL operator+ (RATIONAL &rhs);
		RATIONAL operator- (RATIONAL &rhs);
		RATIONAL operator/ (RATIONAL &rhs);
		RATIONAL operator* (RATIONAL &rhs);
		friend ostream &operator << (ostream& output, RATIONAL &rhs);
		friend istream &operator >> (istream& input, RATIONAL &rhs);
};
#endif
