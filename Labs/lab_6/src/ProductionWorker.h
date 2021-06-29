/**
 * @author      : root (root@xander-MS-7B49)
 * @file        : ProductionWorker
 * @created     : Sunday Nov 03, 2019 14:20:23 PST
 */
#include "employee.h"
#ifndef PRODUCTIONWORKER_H

#define PRODUCTIONWORKER_H

class ProductionWorker: public Employee {
	private:
		int shift;
		double payRate;
	public:
		ProductionWorker();
		ProductionWorker(int shift, double payRate);
		int getShift();
		void setShift(int shift);
		double getPayRate();
		void setPayRate(double payRate);	
};


#endif /* end of include guard PRODUCTIONWORKER_H */

