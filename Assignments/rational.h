#ifndef RATIONAL_H
#define RATIONAL_H
class RATIONAL
{
	private:
		long num, denom;
		void validate();
	public:
		RATIONAL();
		RATIONAL(long n, long d);
		RATIONAL add(RATIONAL rhs);
		RATIONAL subtract(RATIONALL rhs);
		RATIONAL divide(RATIONAL rhs);
		RATIONAL multiply(RATIONAL rhs);
		void isread(istream &input);
		void print(ostream &out);
}
#endif
