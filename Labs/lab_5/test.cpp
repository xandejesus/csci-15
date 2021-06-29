


#include

// ~~~~~~~~~~~~~~~~~~~~
class DATE
{
	private:
		int month, day, year;
		void validate();
	public:
		Date();
		Date(int m, int d, int y);
		void SetAll(int m, int d, int y);
		void print_dateSlash(ostream output);
		void print_dateDash(ostream output);
		void print_dateNorm(ostream output)i;
		void GetYear();
		void GetMonth();
		void GetDay();
}
void Date::SetAll(int m, int d, int y)
{
	*this = DATE(m, d, y);
	*this.validate();
}
DATE::DATE( void )
{
	*this.month = 1;
	*this.day = 1;
	*this.year = 1;
}

DATE::DATE(int m, int d, int y)
{
	*this.month = m;
	*this.day = d;
	*this.year = y;
	*this.validate();
}

void DATE::validate()
{
	if((dates[*this.month - 1] < *this.day) || *this.year <= 0)
	{
		*this = DATE();
	}
}

const int dates[12] = {
	31,28,31,30,31,30,31,31,30,31,30,31
}
const int datesLeap[12] = {
		31,29,31,30,31,30,31,31,30,31,30,31
}



// ~~~~~~~~~~~~~~~~~~~~

