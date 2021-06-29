/**
 * @author      : root (root@xander-MS-7B49)
 * @file        : test
 * @created     : Sunday Nov 03, 2019 14:04:44 PST
 */

#include "employee.h"
#include "ProductionWorker.h"
#include <iostream>

using namespace std;
int main()
{
	Employee brad;
	Employee stanley("Lebron", 66, 12, 13, 14);
	cout << stanley.getName() << endl;
	ProductionWorker manu;
	cout << manu.getName() << endl;
	cout << manu.getShift() << endl;
}


