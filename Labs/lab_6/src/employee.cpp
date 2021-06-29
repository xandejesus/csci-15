/**
 * @author      : root (root@xander-MS-7B49)
 * @file        : employee
 * @created     : Sunday Nov 03, 2019 13:43:12 PST
 */

#include "employee.h"

Employee::Employee()
{
	name = "John";
	eNum = 1;
	hireDate[0] = 0;
	hireDate[1] = 0;
	hireDate[2] = 0;	
}

Employee::Employee(const char * name, int eNum, int month, int day, int year)
{
	this->name = name;
	this->eNum = eNum;
	this->hireDate[0] = month;
	this->hireDate[1] = day;
	this->hireDate[2] = year;
}

const char * Employee::getName()
{
	return name;
}

void Employee::setName(const char * name)
{
	this->name = name;
}

int Employee::getNum()
{
	return eNum;
}
void Employee::setNum(int eNum)
{
	this->eNum = eNum;
}
