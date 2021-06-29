// This is the rational class.


#include "rational.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
// ~~~~~~~~~~~~~~~~~~~~

RATIONAL::RATIONAL(void)
{
	num = 0;
	denom = 1;
}

RATIONAL::RATIONAL(long n, long d)
{
	num = n;
	denom = d;
	this->validate();
}
RATIONAL RATIONAL::add(RATIONAL rhs)
{
	RATIONAL sum;
	sum.num = num * rhs.denom + rhs.num * denom;
	sum.denom = denom * rhs.denom;
	sum.validate();
	return sum;
}
RATIONAL RATIONAL::subtract(RATIONAL rhs)
{
	RATIONAL sum;
	sum.num = num * rhs.denom  - rhs.num * denom;
	sum.denom = denom * rhs.denom;
	sum.validate();
	return sum;
}
RATIONAL RATIONAL::divide(RATIONAL rhs)
{
	RATIONAL product;
	product.num = num * rhs.denom;
	product.denom = denom * rhs.num;
	product.validate();
	return product;
}
RATIONAL RATIONAL::multiply(RATIONAL rhs)
{
	RATIONAL product;
	product.num = num * rhs.num;
	product.denom = denom * rhs.denom;
	product.validate();
	return product;
}
void RATIONAL::print(ostream &output)
{
	output << "( " << num << " / " << denom << " ) " << flush;
}
void RATIONAL::isread(istream &input)
{
	char garbage;
	input >> garbage;
	input >> num;
	input >> garbage;
	input >> denom;
	input >> garbage;
	validate();
}
void RATIONAL::validate()
{
	if (num == 0 || denom == 0)
	{
		num = 0;
		denom = 1;
	}
	else if(denom < 0)
	{
		num = -num;
		denom = -denom;
	}
	reduce();

}
void RATIONAL::reduce()
{
	if ( num  == 0)
	{
		return;
	}
	long r;
	long x = abs(num);
	long P = abs(denom);
	while(x % P)
	{
		r = x % P;
		P = x;
		x = r;
	}
	num /= P;
	denom /= P;
}
RATIONAL RATIONAL::operator+ (RATIONAL &rhs)
{
	RATIONAL answer;
	answer = add(rhs);	
	return answer;
}
RATIONAL RATIONAL::operator- (RATIONAL &rhs)
{
	RATIONAL answer;
	answer = subtract(rhs);
	return answer;
}
RATIONAL RATIONAL::operator* (RATIONAL &rhs)
{
	RATIONAL answer;
	answer = multiply(rhs);
	return answer;
}
RATIONAL RATIONAL::operator/ (RATIONAL &rhs)
{
	RATIONAL answer;
	answer = divide(rhs);
	return answer;
}
ostream &operator << (ostream &output, RATIONAL &rhs)
{
	rhs.print(output);	
	return output;
}
istream &operator >> (istream &input, RATIONAL &rhs)
{
	rhs.isread(input);
	return input;
}

// ~~~~~~~~~~~~~~~~~~~~

