/**
 * @author      : root (root@xander-MS-7B49)
 * @file        : productionworker
 * @created     : Sunday Nov 03, 2019 14:30:26 PST
 */

#include "ProductionWorker.h"

ProductionWorker::ProductionWorker()
{
   shift = 0;
   payRate = 0;
}

ProductionWorker::ProductionWorker(int shift, double payRate)
{
	this->shift = shift;
	this->payRate = payRate;
}

int ProductionWorker::getShift()
{
	return shift;
}

void ProductionWorker::setShift(int shift)
{
	this->shift = shift;
}

double ProductionWorker::getPayRate()
{
	return payRate;
}

void ProductionWorker::setPayRate(double payRate)
{
	this->payRate = payRate;
}
