#include <iostream>
using namespace std;
#ifndef DATE_H
#define DATE_H
class DATE
{
	private:
		int month, day, year;
		void validate();
		int isLeap();
	public:
		DATE();
		DATE(int m, int d, int y);
		void SetAll(int m, int d, int y);
		void print_dateSlash(ostream &output);
		void print_dateSpace(ostream &output);
		void print_dateNorm(ostream &output);
		void GetYear();
		void GetMonth();
		void GetDay();
		int Difference(DATE &d2);

};
#endif
