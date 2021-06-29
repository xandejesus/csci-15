//
//
//
//
//
//
//
// Sorry I have no idea what this file is for whoever is reading this.

#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
const int rows = 100;
const int columns = 100;
// ~~~~~~~~~~~~~~~~~~~~~
struct positions{
	int bridgepos[2][2];
	int mousepos [2];
	int mapdimensions[2];
};
positions takemap(ifstream &input, int map [][columns])
{
	positions MousePositions;
	int rows_1, columns_1;
	int rowcount = 0, columncount = 0;
	input >> rows_1;
	input >> columns_1;
	MousePositions.mapdimensions[0] = rows_1;
	MousePositions.mapdimensions[1] = columns_1;
	int bridgeposrows = 0, bridgeposcols = 0;
	int testposition;
	for ( int cont = 0; cont < (rows_1 * columns_1); cont++)
	{
		
		input >> testposition;
		if(((rowcount == 0) || (columncount == 0) || (columncount ==  (columns_1 -1) || (rowcount == (rows_1 -1)))  ) && (testposition == 0))
		{

			if (bridgeposcols == 2)
			{
				cout << "Error: Too many Islands" << endl;
			}
			MousePositions.bridgepos[bridgeposrows][bridgeposcols++] = rowcount;
			MousePositions.bridgepos[bridgeposrows++][bridgeposcols] = columncount;
			bridgeposcols = 0;
		}
		if(testposition == 1)
		{
		
			MousePositions.mousepos[0] = rowcount;
			MousePositions.mousepos[1] = columncount;
		}
		if(columncount++ > (columns_1 - 2))
		{
			columncount = 0;
			rowcount++;
		}
	}
	return MousePositions;	
}
void makemap(int row, int column, ofstream &output,  positions posits, int mymap[][columns])
{
	int rowcount = 0, columncount = 0;
	while(rowcount < row)
	{
		mymap[rowcount][columncount] = -1;
		rowcount++;
	}
	rowcount = 0;
	columncount = (column - 1);
	while(rowcount < row)
	{
		mymap[rowcount][columncount] = -1;
		rowcount++;
	}
	columncount = 0;
	rowcount = 0;
	while(columncount < column)
	{
		mymap[rowcount][columncount] = -1;
		columncount++;
	}
	rowcount = (row - 1);
	columncount = 0;
	while(columncount < column)
	{
		mymap[rowcount][columncount] = -1;
		columncount++;

	}
	rowcount = posits.mousepos[0];
	columncount = posits.mousepos[1];
	mymap[rowcount][columncount] = 1;
	rowcount = posits.bridgepos[0][0];
	columncount = posits.bridgepos[0][1];
	mymap[rowcount][columncount] = 0;
	rowcount = posits.bridgepos[1][0];
	columncount = posits.bridgepos[1][1];
	mymap[rowcount][columncount] = 0;
	return;
}

void printmap(ofstream &output, int row, int column, int maps [][columns])
{
	output << "Dimensions: " << row << "x" << column << endl;
	for(int rowcount = 0; rowcount < row; rowcount++)
	{
		for (int columncount = 0; columncount < column; columncount++)
		{
			output << setw(4) << right << maps[rowcount][columncount] << flush;
		}
		output << endl;
	}
}

// ~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char * argv[])
{
	int map [rows][columns];
	positions posits;
	if(argc != 3)
	{
		cout << "Please specify an input and an output file." << endl;
		return -1;
	}
	ifstream input(argv[1]);
	ofstream output(argv[2]);
	if(!input)
	{
		cout << "Error opening input file." << endl;
		return -1;
	}
	posits = takemap(input, map);
	makemap(posits.mapdimensions[0], posits.mapdimensions[1], output, posits, map);
	printmap(output, posits.mapdimensions[0], posits.mapdimensions[1], map);
	int currentmousepos[2];
	currentmousepos[0] = posits.mousepos[0];
	currentmousepos[1] = posits.mousepos[1];
	cout << currentmousepos[0] << " " << currentmousepos[1] << endl;


}

