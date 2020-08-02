#ifndef DATABASE_H_
#define DATABASE_H_

#include <iostream>
#include <stdlib.h>
#include "Employee.h"

//This class manages the Employees in the company
class DataBase {

//data members
private:
	Employee** _employees;
	int _numOfWorkers;
	static int arrLength;//size of the database - how much workers can be in the database

//Methods
public:
	DataBase();
	DataBase(const DataBase& copyData);
	~DataBase();
	Employee* getEmployee(int id) const;
	void addEmployee(const Employee* newEmployee);
	void removeEmployee(int id);
	void print() const;
};



#endif /* DATABASE_H_ */
