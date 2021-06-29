#include "TIME2.h"
#include <iomanip>
#include <iostream>
using namespace std;



TIME2::TIME2( void )  // :: is the "scope resolution operator"
{
    hour = minute = sec = 0;
    cout << "I'm in the default constructor now\n" << flush;
    // constructors CANNOT return!
}
// constructor, set time if it is legal, else 0's
TIME2::TIME2( int h, int m, int s )
{
    setTime( h, m, s );
    cout << "I'm in the normal constructor now\n" << flush;
}
// set time to an outside time, if time is legal
void TIME2::setTime( int h, int m, int s )
{
    // -> operator, LHS is pointer to struct or class object
    //              RHS is field in a struct or object
    hour = ( h >= 0 && h <= 23 ) ? h : 0;
    // (*ptr).field is equivalent to ptr->field; -> is MUCH more common
    minute  = ( m >= 0 && m <= 59 ) ? m : 0;
    // for member variables, you don't need to use "this", it's the default
    sec  = ( s >= 0 && s <= 59 ) ? s : 0;
}
// print time in MILITARY or NORMAL format
void TIME2::printTime( int mode )
{
    switch( mode )
    {
    case MILITARY :
        cout << setw(2) << setfill('0') << hour << ':'
             << setw(2) << setfill('0') << minute << ':'
             << setw(2) << setfill('0') << sec;
        break;
    case NORMAL   :
        cout << (hour == 0 || hour == 12 ? 12 : hour % 12) << ':'
             << setw(2) << setfill('0') << minute << ':'
             << setw(2) << setfill('0') << sec << ' '
    // both results of ?: must be the same type, here C-strings
             << (hour >= 12 ? "PM" : "AM") << flush;
        break;
    default       :
        cout << hour << ':' << minute << ':' << sec;   // unspecified format
    }
    return;
}
// add one second to time in "self"
void TIME2::increment( void )
{
    sec++;
    if( sec > 59 )
    {
        sec = 0;
        minute++;
        if( minute > 59 )
        {
            minute = 0;
            hour++;
            if( hour > 23 )
            {
                hour = 0;
            }
        }
    }
}
#if 0
void printTimes( TIME1 time1, TIME2 time2 )
{
    cout << "time1 is " << time1.hour << ' '
         << time1.minute << ' ' << time1.sec << endl;
    cout << "time2 military ";
    time2.printTime( MILITARY );
    cout << endl << "time2 normal   ";
    time2.printTime( NORMAL );
    cout << endl;
    return;
}
#endif
