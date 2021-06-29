#ifndef RATIONAL_H
#define RATIONAL_H
class RATIONAL
{
	private:
		long top, bottom;
		void validate
	public:
		RATIONAL();
		RATIONAL(long n, long d);
		RATIONAL add(RATIONAL augend);
		RATIONAL subtract(RATIONALL subtrend);
		RATIONAL divide(RATIONAL dividend);
		RATIONAL multiply(RATIONAL multiplend);
}
#endif
