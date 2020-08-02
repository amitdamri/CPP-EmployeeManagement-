/*
 * Employee.cpp
 *
 *  Created on: Dec 14, 2018
 *      Author: ise
 */
#include "Employee.h"

int Employee::workersNum;

/* Constructor */
Employee::Employee(char* Name, int ID, double salary){

	if (Name != NULL && ID >= 0 && salary >= 0) {
		_firstName = new char[strlen(Name)+1];
		if (_firstName != NULL) {
			strcpy(_firstName, Name);
			_ID = ID;
			_salary = salary;
			workersNum++;
		}
	}

}

/* Copy Constructor */
Employee::Employee(const Employee& other){

	if (&other != NULL && other._firstName != NULL && other._ID >= 0 && other._salary >= 0){
		_firstName = new char[strlen(other._firstName)+1];
		if (_firstName != NULL) {
			strcpy(_firstName, other._firstName);
			_ID = other._ID;
			_salary = other._salary;
			workersNum++;
		}
	}
}

/* Default Constructor */
Employee::Employee(){

	_firstName = new char[5];
	if (_firstName != NULL) {
		strcpy(_firstName, "Name");
		_ID = 0;
		_salary = 0;
		workersNum++;
	}

}

/* Destructor */
Employee::~Employee(){

	if (_firstName != NULL) {
		delete[] _firstName;
		_firstName = NULL;
		workersNum--;
	}
}

/* Calculates cost of office party */
int Employee::planOfficeParty()const{

	return 10*workersNum;
}

/* Compares two employees by their ID number */
bool Employee::operator==(const Employee& other) const {

	return _ID == other._ID;
}

/* Checks if the employee in the left-hand of the operator earns more the the
employee in the right-hand */
bool Employee::operator>(const Employee& other) const{

	return _salary > other._salary;
}

/* Sets the name of the employee in the left-hand of the operator to the name
of the employee in the right-hand */
Employee& Employee::operator=(const Employee& other){

	if (this == &other)//the same employee
		return *this;
	int length = strlen(other._firstName) + 1;
	char *tmp = new char[length];
	if (tmp != NULL) {
		strcpy(tmp, other._firstName);
		delete[] _firstName;
		_firstName = new char[strlen(tmp) + 1];
		strcpy(_firstName, tmp);
		delete [] tmp;
	}

	return *this;

}

/* Increases the salary of the employee in the left-hand of the operator by
adding the salary of the employee in right-hand to his salary */
Employee& Employee::operator+(const Employee& other){

	_salary = _salary + other._salary;
	return *this;
}

/* Operator prefix ++ - increases employee's salary in 100 and returns the
new salary*/
Employee& Employee::operator++() {

	_salary += 100;

	return *this;
}

/* Operator postfix ++ - increases empoyee's salary in 100 and returns employee reference with
original salary (before increasing)*/
Employee Employee::operator++(int x){

	Employee tmp (*this);
	_salary += 100;
	return tmp;

}

/* Operator += changes the name of the employee in the left-hand of the operator
by concatenate the name of the employee in the right-hand of the operator
to his name*/
Employee& Employee::operator+=(const Employee& other) {

	int length = strlen(_firstName) + strlen(other._firstName) + 1;
	char *tmp = new char[length];
	if (tmp == NULL)
		return *this;

	int index1 = strlen(_firstName);
	for (int i = 0; i < index1; i++) {
		tmp[i] = _firstName[i];
	}


	int index2 = strlen(other._firstName);
	for (int i = 0; i < index2; i++) {
		tmp[i+index1] = other._firstName[i];
	}

	tmp[length - 1] = '\0';

	delete[] _firstName;

	_firstName = new char[strlen(tmp) + 1];
	strcpy(_firstName, tmp);
	delete [] tmp;

	return *this;
}

/* Operator << overload - prints employee's details */
ostream& operator<<(ostream& out, const Employee& other) {

	cout << "Name:" << other._firstName << endl;
	cout << "ID:" << other._ID << endl;
	cout << "Salary:" << other._salary << endl;

	return out;

}

/* Getters */
int Employee::getID() const {

	return _ID;
}

double Employee::getSalary() const {

	return _salary;

}
