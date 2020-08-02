/*
 * Employee.h
 *
 *  Created on: Dec 14, 2018
 *      Author: ise
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//This class represents the employee
class Employee{

//Data members
private:
	char* _firstName;
	int _ID;
	double _salary;
	static int workersNum;

//Methods
public:
	Employee(char* Name, int ID, double salary);
	Employee(const Employee& copyEmployee);
	Employee();
	~Employee();

	int planOfficeParty()const;
	int getID() const;
	double getSalary() const;

	bool operator==(const Employee&) const;
	bool operator>(const Employee&) const;
	Employee& operator=(const Employee&);
	Employee& operator+(const Employee&);
	Employee& operator++(); // ++number
	Employee operator++(int x); // number++
	Employee& operator+=(const Employee&);
	friend ostream& operator<<(ostream& out, const Employee& other);

};



#endif /* EMPLOYEE_H_ */
