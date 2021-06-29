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
        for (i=j;i<m-j;i++) a[i][j]=k++;
        for (i=j+1;i<n-j;i++) a[m-1-j][i]=k++;
        for (i=m-2-j;i>=j;i--) a[i][n-1-j]=k++;
        for (i=n-2-j; i>=j+1;i--) a[j][i]=k++;
        j=j+1;
    }
}
void printspiral(ofstream&output, int a[15][20], int m, int n)
{
    for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                output << setw(m*n+1) << a[i][j] << "  ";
            output << endl;
        }
}
int main(int argc, char *argv[])
{
    int a[15][20];
    if (argc!=3)
    {
        cout << "error" << endl;
        return 0;
    }
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    if (!input)
    {
        cout << "error" << endl;
        return 0;
    }
    for (int i=0;i<15;i++)
        for (int j=0;j<20;j++)
            a[i][j]=0;
    int m,n;
    input >> m >> n;
    makespiral(a,m,n);
    printspiral(output,a,m,n);
    input.close();
    output.close();
    return 0;
}


