#include "DATE.h"
#include <fstream>
using namespace std;

void DATE::SetAll(int m, int d, int y)
{
	// *this = DATE(m, d, y);
	month = m;
	day = d;
	year = y;
	validate();
};
DATE::DATE( void )
{
	month = 1;
	day = 1;
	year = 1;
};
DATE::DATE(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
	validate();
};

void DATE::validate()
{
	static int dates[12][2] = {
	{31, 31},{28,29}, {31, 31}, {30, 30}, {31,31}, {30, 30},{31, 31},
	{31, 31}, {30, 30}, {31, 31}, {30, 30}, {31,31}
	};
	int num = 0;
	num = isLeap();
	
	if((dates[month - 1][num] < day) || year <= 0 || month > 1 || month < 12)
	{
		// *this = DATE();
		month = 1;
		day = 1;
		year = 1;
	}
};
int DATE::isLeap()
{
	if(!(year % 4))
	{
		if(!(year % 100))
		{
			return(!(year % 400));	
		}
		return 1;
	}
	return 0;
};

void DATE::print_dateSlash(ostream &output)
{
	output << month << '/' << day << '/' << year << endl;
};
void DATE::print_dateSpace(ostream &output)
{
	static const char * months[12] = {
	"January", "February", "March", "April", "May", "June","July", "August", 
	"September", "October", "November", "December"
};
	output << day << " " << months[month -1] << " " << year << endl;
};
void DATE::print_dateNorm(ostream &output)
{
	static const char * months[12] = {
	"January", "February", "March", "April", "May", "June","July", "August", 
	"September", "October", "November", "December"
};
	output << months[month -1] << " " << day <<  " , " << year << endl;
};
int DATE::Difference(DATE &d2)
{
	int cMonth = month, cDay = day;
	int diff;
	int cont = year;
	int num;
	/*cont = d2.year > year ? year : d2.year;
	int final = d2.year > year ? d2.year : year;
	if(cont == year)
	{
		cMonth = month;
		cDay = day;
	}*/
	DATE cYear(cMonth, cDay, cont);

		static int dates[12][2] = {
		{31, 31},{28,29}, {31, 31}, {30, 30}, {31,31}, {30, 30},{31, 31},
		{31, 31}, {30, 30}, {31, 31}, {30, 30}, {31,31}
		};
		num = isLeap();
		while(cont != final)
		{
			if(cYear.year == cont)
			{
				diff++;
				++cDay;
				if(cDay > dates[cMonth][num])
				{	
					cDay = 1;
					cMonth++;
				}
				if(cMonth > 12)
				{
					cMonth = 1;
					cont++;	
				}
				cYear.SetAll(cMonth, cDay, cont);
				continue;
			}
			for(cMonth = cMonth; cMonth <= 12; cMonth++)
			{
				num = isLeap();
				diff += dates[cMonth][num]; 

			}

	}
	return diff;
};