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
void makespiral(int a[15][20], int m, int n)
{
    int k=1,i,j=0;
    while  (k<=m*n)
    {
        for (i=j;i<m-j;i++)
            a[i][j]=k++;
        if (i==j) break;
        for (i=j+1;i<n-j;i++) a[m-1-j][i]=k++;
        if (i==j+1) break;
        for (i=m-2-j;i>=j;i--) a[i][n-1-j]=k++;
        if (i==m-2-j) break;
        for (i=n-2-j; i>=j+1;i--) a[j][i]=k++;
        j=j+1;
    }
}
void printspiral(ofstream &output, int a[15][20], int m, int n)
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

void clearr(int a[15][20])
{
    for (int i=0;i<15;i++)
        for (int j=0;j<20;j++)
            a[i][j]=0;
}
int main(int argc, char *argv[])
{
    int a[15][20];
    if (argc!=2)
    {
        cout << "error" << endl;
        return 0;
    }
    ofstream output(argv[1]);
    int b[20][2]={{1,1},{1,2},{2,1},{2,2},{3,3},{4,4},{5,5},{4,7},{7,4},{4,8},{6,4},{15,20}, {6,6},{13,13},{1,3},{4,1}};
    int i;
    while(b[i][0])
    {
        clearr(a);
        makespiral(a,b[i][0],b[i][1]);
        printspiral(output,a,b[i][0],b[i][1]);
	i++;
    }
    output.close();
    return 0;
}
