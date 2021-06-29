/**
 * @author      : root (root@xander-MS-7B49)
 * @file        : employee
 * @created     : Sunday Nov 03, 2019 11:05:24 PST
 */

#ifndef EMPLOYEE_H

#define EMPLOYEE_H
class Employee
{
	protected:
		String name;
		int eNum; // employee number
		int hireDate[3];
	public:
		Employee();
		Employee(String name, int eNum, int month, int day, int year);
		String getName();
		void setName(const char * name);
		int getNum();
		void setNum(int eNum);
};



#endif /* end of include guard EMPLOYEE_H */

