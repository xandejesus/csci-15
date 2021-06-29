#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define row 15
#define column 20
void makespiral(int a[row][column], int m, int n)
{
    int k=1,i,j=0;
    while  (k<=m*n)
    {
        for (i=j;i<m-j;i++) a[i][j]=k++;
        for (i=j+1;i<n-j;i++) a[m-1-j][i]=k++;
        for (i=m-2-j;i>=j;i--) a[i][n-1-j]=k++;
        for (i=n-2-j; i>=j+1;i--) a[j][i]=k++;
        j=j+1;
    }
}
void printspiral(int a[row][column], int m, int n, ofstream &output)
{
   	output << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n \n" << flush;
	output << "Dimensions: " << m << "x" << n << "\n \n" << flush;
	for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                output << setw(4) << right << a[i][j] << flush;
            output << endl;
        }
}
void clearspiral(int a[][column], int rownum, int columnnum)
{
	for(int rowcount = 0; rowcount < rownum; rowcount++)
	{
		for(int columncount = 0; columncount < columnnum; columncount++)
		{
			a[rowcount][columncount] = 0;
		}
	}
}
int main(int argc, char* argv[])
{
    if(!argc)
    {
	cout << "Please specify an output file." << endl;
	return -1;
    }
    ofstream output(argv[1]);
    int a[row][column];
    int cornersizes[20][2];
    cornersizes[0][0] = 1;
    cornersizes[0][1] = 1;
    cornersizes[1][0] = 1;
    cornersizes[1][1] = 2;
    cornersizes[2][0] = 2;
    cornersizes[2][1] = 2;
    cornersizes[3][0] = 2;
    cornersizes[3][1] = 3;
    cornersizes[4][0] = 3;
    cornersizes[4][1] = 3;
    cornersizes[5][0] = 3;
    cornersizes[5][1] = 4;
    cornersizes[6][0] = 4;
    cornersizes[6][1] = 4;
    cornersizes[7][0] = 5;
    cornersizes[7][1] = 5;
    cornersizes[8][0] = 4;
    cornersizes[8][1] = 7;
    cornersizes[9][0] = 7;
    cornersizes[9][1] = 4;
    cornersizes[10][0] = 4;
    cornersizes[10][1] = 8;
    cornersizes[11][0] = 6;
    cornersizes[11][1] = 4;
    cornersizes[12][0] = 15;
    cornersizes[12][1] = 20;
    cornersizes[13][0] = 2;
    cornersizes[13][1] = 1;
    int counter = 0, index = 0;
    while(cornersizes[counter][index])
    {
	clearspiral(a , row, column);
	int index_1 = cornersizes[counter][index];
	int index_2 = cornersizes[counter][++index];
	makespiral(a, index_1, index_2);
	printspiral(a, index_1, index_2, output);
	counter++;
	index = 0;

    }
    return 0;
}
