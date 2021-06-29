// lab_3.cpp
//
// Xander de Jesus Huy Dang Lam
//
// 9 - 25 - 2019
// CSCI-15 2D array Program
// The program takes some cornersizes, and prints out arrays in spiral pattern
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
void makespiral(int *a, int m, int n)
{
    int k=1,i,j=0;
    while  (k<=m*n)
    {
        for (i=j;i<m-j;i++)
            *(a + i * n + j)=k++;
        if (i==j) break;
        for (i=j+1;i<n-j;i++) *(a +m-1-j * n +i)=k++;
        if (i==j+1) break;
        for (i=m-2-j;i>=j;i--) *(a + i * n + n-1-j)=k++;
        if (i==m-2-j) break;
        for (i=n-2-j; i>=j+1;i--) *(a + j * n + i)=k++;
        j=j+1;
    }
}
void printspiral(ofstream &output, int *a, int m, int n)
  {
          output << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << "\n \n" << flush;
          output << "Dimensions: " << m << "x" << n << "\n \n" << flush;
          for (int i=0; i<m; i++)
          {
              for (int j=0; j<n; j++)
                  output << setw(4) << right << *(a + i * n + j) << flush;
              output << endl;
         }
  }

void clearr(int *a , int row, int col)
{
    for (int i=0;i<row;i++)
        for (int j=0;j<col;j++)
            *(a + i * col + j)=0;
}
int main(int argc, char *argv[])
{
 
    if (argc!=2)
    {
        cout << "error" << endl;
        return 0;
    }
    ofstream output(argv[1]);
    int b[20][2]={{1,1},{1,2},{2,1},{2,2},{3,3},{4,4},{5,5},{4,7},{7,4},{4,8},{6,4},{15,20}, {6,6},{13,13},{1,3},{4,1}};
	int b1[1][1];
	int b2[1][2];
	int b3[2][1];
	int b4[2][2];
	int b5[3][3];
	int b6[4][4];
	int b7[5][5];
	int b8[4][7];
	int b9[7][4];
	int b10[4][8];
	int b11[6][4];
	int b12 [15][20];
	int b13[6][6];
	int b14[13][13];
	int b15[1][3];
	int b16[4][1];
	int *bases[20] = {*b1, *b2, *b3, *b4, *b5, *b6, *b7, *b8, *b9, *b10, *b11, *b12, *b13, *b14, *b15, *b16};
	int i;
    while(b[i][0])
    {
        clearr(bases[i] , b[i][1], b[i][2]);
        makespiral(bases[i],b[i][0],b[i][1]);
        printspiral(output,bases[i],b[i][0],b[i][1]);
	i++;
    }
    output.close();
    return 0;
}
