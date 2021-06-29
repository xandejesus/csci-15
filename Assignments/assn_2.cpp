// assn_2.cpp
//
// Xander de Jesus
// 9 - 18 - 2019
// CSCI-15 Array Assignment
//
// Overview: string data is taken from a file and put into a line
// Line is then tokenized and individual tokens are sorted into arrays
// If a word has been seen it is not added into the array, but its 
// corresponding int value is incremented.
// The statistics are printed at the end.
#include <iostream>
#include <fstream>

using namespace std;

const int rows = 100;
const int columns = 16;
// ~~~~~~~~~~~~~~~~~~~~~
void assignarrays (int cont, int &arraynum, char uniquewords[][columns], int wordamnts [], char * str1);
int comparestring(char uniquewords[][columns], char * str1, int arraynum);
int stringsequal(char uniquewords[][columns], int wordamnts[100], ifstream &input, char longestword[], char smallestword[])
{
	static int arraynum = 0;
	int shortestlength = 15;
	bool equal;
	int length, longestlength = 0;
	char * pen;
	char firstword[200];
	int cont;
	if(input.eof())
	{
		return arraynum;
	}
	while(true)
	{
		if(input.eof())
		{
			return arraynum;
		}
		input.getline(firstword, 200);
		pen = strtok(firstword, " ,.\n");
		while(pen != NULL)
		{
			length = strlen(pen); 
		// checks for largest and smallest word
			if(length < shortestlength)
			{
				shortestlength = length;
				strcpy(smallestword, pen);
			}
			if(length > longestlength)
			{
				longestlength = length;
				strcpy(longestword, pen);
			}
			cont  = comparestring(uniquewords, pen, arraynum);
			assignarrays(cont, arraynum,uniquewords, 
					wordamnts, pen);
			
			pen = strtok(NULL, " ,.?\n");
			
		}
	}

}

int comparestring(char uniquewords[][columns], char * str1, int arraynum)
{
	
	bool equal = true;
	for (int cont = 0; cont < arraynum; cont++)
	{
		equal = strcmp(uniquewords[cont], str1);
		if (!equal)
		{
			return cont;
		}
	}
	return -1;
} // compares strings, sees if they are equal
void assignarrays (int cont, int &arraynum, char uniquewords[][columns], int wordamnts [], char * str1)
{
	if(cont >= 0)
	{
		int swap = wordamnts[cont];
		wordamnts[cont] = ++swap;
	}
	else
	{
		wordamnts[arraynum] = 1;
		strcpy(uniquewords[arraynum++], str1);
	}
} // decides what to do based on if the word has been seen before
void prinstuff(char uniquewords[][16], int arraynum, int wordamnts[], ofstream &output, 
	 char *	longestword, char * smallestword)
{
	int arraynum1, arraynum2;
	if(!arraynum)
	{
		cout << "Your file had no data" << endl;
		output << "Your input file had no data" << endl;
		return;
	}
	output << "UNIQUE WORD \t \t AMOUNT OF TIMES SEEN" << endl;
	for(int cont = 0; cont < arraynum; cont++)
	{
		output << uniquewords[cont] << "\t \t \t \t" << wordamnts[cont] << endl;
	}
	output << "Longest word: " << longestword << endl;
	output << "Shortest word: " << smallestword << endl;

} // This function prints the stuff
// ~~~~~~~~~~~~~~~~~~~~~
int main(int argc, char* argv[])
{
	char longestword [columns]; // longestword in an array
	char smallestword[columns]; // shortest word in an array
	int arraynum, wordamnts[100]; // stores word amounts
	char uniquewords[rows][columns]; // stores 100 unique words
	if (argc != 3)
	{
		cout << "Enter your files again. Goodbye." << endl;
	}
	ifstream input;
	ofstream output;
	input.open(argv[1]);
	output.open(argv[2]);
	if(!input)
	{
		cout << "Trouble opening files. Goodbye" << endl;
	}
	arraynum = stringsequal(uniquewords, wordamnts,input,
			longestword, smallestword);
	prinstuff(uniquewords, arraynum, wordamnts, output, longestword, smallestword);
	return 0;
}

