/**
 * @author      : xanderdejesus (xanderdejesus@Xanders-MacBook-Air.local)
 * @file        : assn_8
 * @created     : Thursday Dec 12, 2019 14:09:29 PST
 */

// Xander de Jesus
//
// assn_8.cpp
// 12 - 12 - 2019
// CSCI-15 Final Assignment
// Sorry professor, had to turn this in late because I both forgot about it
// being the last day of class yesterday and I accidentally deleted the first
// version of it on the CLI. oops. Please accept, it works for the most part
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

const int nRows = 50;
const int nCols = 50;
struct mazeSize {
	int r;
	int c; // Holds the logical size of the maze array, this was the easiest thing
	// I could thik of
};

bool checkPos(int r, int c, char **m, mazeSize s)
{
	if(r < s.r && r >= 0 && c < s.c && c >= 0 && m[r][c] == ' ')
	{
		return true;
	}
	return false;
}

bool solveMaze(int r, int c, char **m, 
		mazeSize s)
{
	
	if (r == s.r - 1 && c == s.c - 1)
	{
		m[r][c] = '#';
		return true;
	}
	if(checkPos(r, c, m, s))
	{
		m[r][c] = '#';
		if (solveMaze(r - 1, c, m, s))
			return true;
		if (solveMaze(r, c + 1, m, s))
			return true;
		if (solveMaze(r + 1, c, m, s))
			return true;
		if (solveMaze(r, c - 1, m, s))
			return true;
		return false;
	}
	return false;
}

mazeSize getMaze(istream &in, char **m)
{
	mazeSize s;
	string line;
	in >> s.r;
	in >> s.c;
	getline(in, line);
	for(int r1 = 0; r1 < s.r; r1++)
	{
		getline(in, line);
		for(int c1 = 0; c1 < s.c; c1++)
		{
			m[r1][c1] = line[c1];
		}
	}
	return s;
}

void printMaze(ostream &out, char **m, mazeSize s)
{
	out << s.r << " " << s.c << endl;
	for(int r = 0; r < s.r; r++)
	{
		for(int c = 0; c < s.c; c++)
			out << m[r][c];
		out << endl;
	}
}
void destroy(char **m)
{
	for(int n = 0; n < nRows; n++)
		delete [] m[n];
	delete []m;
} // Manual memory management to prevent a seg fault.


int main()
{
	string iName, oName;
	cout << "Enter an input file" << endl;
	cin >> iName;
	ifstream input(iName);
	if(!input)
	{
		cout << "input file not found" << endl;
		return -55;
	}
	cout << "Enter an output file" << endl;
	cin >> oName;
	ofstream output(oName);
	char **m;
	m = new char *[nRows];
	for(int n = 0; n < nRows; n++)
		m[n] = new char[nCols];
	mazeSize size = getMaze(input, m);
	solveMaze(0, 0, m, size);	
	printMaze(output, m, size);
	destroy(m);
	output.close();
	input.close();
	return 0;
}
