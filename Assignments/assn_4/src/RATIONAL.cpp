


#include "RATIONAL.h"
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
	product.denom = num * rhs.denom;
	product.validate();
	return product;
}
void RATIONAL::print(ostream &output)
{
	output << "( " << num << " / " << denom << " )" << endl;
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
	else if(num < 0 && denom < 0)
	{
		num = abs(num);
		denom = abs(denom);
	}
	else if(num >= 0 && denom < 0)
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
	int r;
	int x = abs(num);
	int P = abs(denom);
	while(x)
	{
		r = x % P;
		P = x;
		x = r;
	}
	num /= P;
	denom /= P;
}

// ~~~~~~~~~~~~~~~~~~~~

