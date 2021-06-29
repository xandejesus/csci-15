//	assn_3.cpp
//
//	xander de jesus
//	8-29-2019
//	CSCI-15 Array Program
//	This program does a bunch of things that has to do with arrays
//
//


#include <fstream>
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
const int rows = 100;
const int columns = 100;
// ~~~~~~~~~~~~~~~~~~~~~
struct livestats{
	int drowned;
	int survived;
	int starved;
};

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
		if(((rowcount == 0) || (columncount == 0) || (columncount ==  (columns_1 -1)
						|| (rowcount == (rows_1 -1)))  ) && (testposition == 0))
		{

			if (bridgeposcols == 2)
			{
				cout << "Error: Too many Bridges" << endl;
				return MousePositions;
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
		map[rowcount][columncount] = testposition;
		if(columncount++ > (columns_1 - 2))
		{
			columncount = 0;
			rowcount++;
		}
	}
	return MousePositions;	
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
void MoveMouse(int currentmousepos[2])
{
	static int moves[4][2] = {{ -1, 0}, {0, 1}, {1,0}, {0, -1}}; 
	int randnum = rand() % 4;	
	currentmousepos[0] += moves[randnum][0];
	currentmousepos[1] += moves[randnum][1];
}
livestats looplives(int currentmousepos[2], positions posits, 
		int map[][columns], ofstream &output, int countmap[][columns])
{
	livestats mouselife = {
		0, 0, 0
	};
	int counter;
	for(int cont = 0; cont < 100; cont++)
	{
		counter = 0;
		currentmousepos[0] = posits.mousepos[0];
		currentmousepos[1] = posits.mousepos[1];
		while(counter < 100)
		{
			MoveMouse(currentmousepos);
			countmap[currentmousepos[0]][currentmousepos[1]]++;
			if(map[currentmousepos[0]][currentmousepos[1]] == -1)
			{
				mouselife.drowned++;
				output << "DROWNED on life " << cont << endl;
				break;
			}
			else if(((currentmousepos[0] == posits.bridgepos[0][0]) 
						&& (currentmousepos[1] == posits.bridgepos[0][1])) ||
					((currentmousepos[0] == posits.bridgepos[1][0] ) 
					 && (currentmousepos[1] == posits.bridgepos[1][1]) ))
			{
				mouselife.survived++;
				output << "YOU LIVED ON life " << cont << endl;
				break;
			}	
			counter++;
		}
		if(counter == 100)
		{
			mouselife.starved++;
			output << "YOUR MOUSE STARVED TO DEATH LOL on life " << cont <<  endl;
		}
	}
	return mouselife;
}

void ClearMap(int countmap[rows][columns], int row, int column)
{
	for(int rowcount = 0; rowcount < row; rowcount++)
	{
		for(int columncount = 0; columncount < column; columncount++)
		{
			countmap[rowcount][columncount] = 0;
		}
	}
	return;
}

// ~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char * argv[])
{
	if (argc == 4)
	{
		srand(atoi(argv[3]));
	}
	else
		srand(time(NULL));
	int map [rows][columns];
	int countmap [rows][columns];
	positions posits;
	if(argc < 3)
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
	printmap(output, posits.mapdimensions[0], posits.mapdimensions[1], map);
	int currentmousepos[2];
	currentmousepos[0] = posits.mousepos[0];
	currentmousepos[1] = posits.mousepos[1];

	ClearMap(countmap, posits.mapdimensions[0], posits.mapdimensions[1]);
	livestats mouselife = looplives(currentmousepos, posits, map, output, countmap);
	output << "Drowned: " << mouselife.drowned << " times" << endl;
	output << "Survived: " << mouselife.survived << " times" << endl;
	output << "Starved: " << mouselife.starved << " times" << endl;
	printmap(output, posits.mapdimensions[0], posits.mapdimensions[1], countmap);
	output.close();
	input.close();

}

