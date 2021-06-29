//
//
//
//
//
//
//


#include <fstream>
#include <iomanip>
using namespace std;
// ~~~~~~~~~~~~~~~~~~~~~


// ~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char * argv[])
{
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);
	int map[20][20];
	ofstream despacito(argv[3]);
	for(int rows = 0; rows < n1; rows++)
	{
		for(int columns = 0; columns < n2; columns++)
		{
				map[rows][columns] = 0;
				if(rows == 0 || rows == n1 - 1 || columns == 0 || columns == n2 -1)
				{
					map[rows][columns] = -1;
				}
				despacito << setw(4) << map[rows][columns] << flush;
				
		}
		despacito << endl;
	}
	despacito.close();



}

