/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : palendrome
 * @created     : Wednesday Nov 20, 2019 08:26:42 PST
 */

#include "palindrome.h"
bool iPalindrome(string d)
{
	int x = d.length() - 1;
	int count1 = x;
	int count2 = 0;
	bool palindrome;
	do{
		count2 = isalpha(d[count2]) || d[count2] == ' ' ? count2 : count2 + 1;
		x = isalpha(d[x]) || d[count2] == ' ' ? x : x - 1;
		palindrome = (tolower(d[count2]) == tolower(d[x]));
		x--;
	}while(count2++ < x);
	palindrome = (count2 >= x);
	return palindrome;
}

bool IsPalindrome(string d, int n, int p)
{
	if(!isalpha(d[n]))
	{
		return(IsPalindrome(d, n + 1, p));
	}
	if(!isalpha(d[p - 1]))
	{
		return(IsPalindrome(d, n, p - 1));
	}
	if (p == n || (p - 1) == n || n > (p - 1))
		return true;
	if(tolower(d[n]) != tolower(d[p - 1]))
	{
		return false;
	}
	return(IsPalindrome(d, n + 1, p - 1));
}

bool rPalindrome(string d)
{
	return IsPalindrome(d, 0, d.length());
}
