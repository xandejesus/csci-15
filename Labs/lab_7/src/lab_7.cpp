/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : test
 * @created     : Wednesday Nov 20, 2019 08:35:35 PST
 */
//
// Ragina Ranjikta, Xander de Jesus
//
// 11 - 20 - 2019
// CSCI-15
// Lab 7
// This program uses functions to check if something is a palindrome 
// using recursion and iteration.
// You shouldn't call the helper directly because it is not what it is 
// designed for. A function should do a single task, all of that task, and
// nothing but that task.


#include "palindrome.h"
#include <iostream>
#include <string>
using namespace std;
const string tt = "This is a Palindrome";
const string ff = "This is not a Palindrome";
int main()
{
	string ss;
	cout << "Enter a sentence or 'quit: " << endl;
	getline(cin,ss,'\n');
	while(ss != "quit")
	{
		if(iPalindrome(ss))
		{
			cout << "<" << ss << "> " << tt <<  endl;
		}
		else
		{
			cout << "<" << ss << "> " << ff << endl;
		}
		if(rPalindrome(ss))
		{
			cout << "<" << ss << "> " << tt << endl;
		}
		else 
		{
			cout << "<" << ss << "> " << ff <<  endl;
		}
		cout << "Enter a sentence or 'quit': "<< endl;
		getline(cin,ss,'\n');
	};
}


