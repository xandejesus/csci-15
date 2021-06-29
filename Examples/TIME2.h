#ifndef TIME2_H
#define TIME2_H
class TIME2  // class definition (I have heard this called a schema)
{
private:// only class functions (methods) can access private members
    int hour;  // whether those members are data or other methods
    int minute;
    int sec;
public:      // any client code can use public data or method
            // method declarations or prototypes
    TIME2();  // default constructor, time 0, 0, 0
    TIME2( int h, int m, int s ); // normal constructor
    void setTime( int h, int m, int s ); // set to time if legal, else 0:0:0
    void printTime( int mode );  // print time in MILITARY or NORMAL style
    void increment( void );   // add one second to time, "wrapping" if needed
};

struct TIME1
{
    int hour;   // 2011 C++: you may default in class definition, e.g. = 0;
    int minute; // = 0; But, if you do, you MAY NOT initialize at declaration!
    int sec;    // = 0;
};
#define MILITARY 1
#define NORMAL 2
#endif // TIME2_h
