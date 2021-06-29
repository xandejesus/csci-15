


#include <rational.h>
#include <iostream>
// ~~~~~~~~~~~~~~~~~~~~

RATIONAL::RATIONAL(void)
{
	this.num = 0;
	this.denom = 1;
}

RATIONAL::RATIONAL(long n, long d)
{
	*this.num = n;
	*this.denom = d;
}
RATIONAL RATIONAL::add(RATIONAL rhs)
{
	RATIONAL sum;
	sum.num = *this.num + rhs.num;
	sum.denom = *this.denom + rhs.denom;
	return sum;
}
RATIONAL RATIONAL::subtract(RATIONAL rhs)
{
	RATIONAL sum;
	sum.num = *this.num - rhs.num;
	sum.denom = *this.denom - rhs.denom;
	return sum;
}
RATIONAL RATIONAL::divide(RATIONAL rhs)
{
	RATIONAL product;
	product.num = *this.num * rhs.denom;
	product.denom = *this.denom * rhs.num;
	return product;
}
RATIONAL RATIONAL::multiply(RATIONAL rhs)
{
	RATIONAL product;
	product.num = *this.num * rhs.denom;
	product.denom = *this.num * rhs.denom;
}
void RATIONAL::print(ostream &out)
{
	out << "( " << num << " / " << denom << " )" << flush;
}
void RATIONAL::isread(istream &input)
{
	char garbage;
	in >> garbage;
	in >> garbage;
	in >> *this.num;
	in >> garbage >> garbage;
	in >> *this.denom;
	in >> garbage;
	in >> garbage;
}

// ~~~~~~~~~~~~~~~~~~~~

