/*
 * DataBase.cpp
 *
 *  Created on: Dec 14, 2018
 *      Author: ise
 */

#include "DataBase.h"

using namespace std;

int DataBase::arrLength;

/* Default Constructor */
DataBase::DataBase(){

	_employees = new Employee*[3];
	if (_employees != NULL) {
		_numOfWorkers = 0;
		arrLength = 3;
	}
}

/* Copy constructor */
DataBase::DataBase(const DataBase& other){

	if (&other != NULL) {
		_employees = new Employee*[3];
		if (_employees != NULL) {
			_employees[0] = new Employee(*((other._employees)[0]));
			_employees[1] = new Employee(*((other._employees)[1]));
			_employees[2] = new Employee(*((other._employees)[2]));
			//if memroy allocation failed, delete all memory allocated
			if (_employees[0] == NULL || _employees[1] == NULL || _employees[2] == NULL ) {
				delete _employees[0];
				_employees[0] = NULL;
				delete _employees[1];
				_employees[1] = NULL;
				delete _employees[2];
				_employees[2] = NULL;
			}
			else {
				_numOfWorkers = other._numOfWorkers;
				arrLength = 3;
			}
		}
	}
}

/* Destructor */
DataBase::~DataBase(){

	for (int i = 0; i < _numOfWorkers; i++){
		delete _employees[i];
		_employees[i] = NULL;
	}
	delete[] _employees;

}

/* Returns employee by given ID or NULL if not exist */
Employee* DataBase::getEmployee(int ID) const {

	for (int i = 0; i < _numOfWorkers; i++) {
		if ( _employees[i]->getID() == ID )
			return _employees[i];
	}
	return NULL;
}

/* Adds employee to database */
void DataBase::addEmployee(const Employee* other){


	bool flag = false;
	int index = 0;

	if (other == NULL) {
		return;
	}

	//add only brand new employees (check by ID)
	if (getEmployee(other->getID()) != NULL){
		delete other;
		cout << "This employee is already in the database" << endl;
		cout << endl;
		return;
	}


	//array is full
	if (arrLength == _numOfWorkers) {
		Employee** newEmployee = new Employee*[_numOfWorkers*2];

		if (newEmployee == NULL) //check if memory increasing failed
			return;

		for (int i = 0; i < _numOfWorkers; i++) {
			newEmployee[i] = new Employee(*(_employees[i]));
			if (newEmployee[i] == NULL) {
				flag = true;
				index = i;
			}
		}

		//memory allocation failed, delete new array
		if (flag == true) {
			for (int i = 0; i < index; i++) {
				delete newEmployee[i];
				newEmployee[i] = NULL;
			}
			return;
		}

		for (int i = 0; i < _numOfWorkers; i++) {
			delete _employees[i];
			_employees[i] = NULL;
		}

		delete[] _employees;
		_employees = newEmployee;
		_employees[_numOfWorkers] = new Employee(*other);
		arrLength = _numOfWorkers*2;
	}

	//there is enough space to add
	else {
		_employees[_numOfWorkers] = new Employee(*other);
	}

	delete other;
	other = NULL;
	_numOfWorkers++;

}

/* Removes employee from database */
void DataBase::removeEmployee(int ID) {

	for (int i = 0; i < _numOfWorkers; i++) {

		if ( _employees[i]->getID() == ID ) {
			delete _employees[i];
			//set pointers accordingly
			for (int j = i; j < _numOfWorkers - 1; j++) {
				_employees[j] = _employees[j+1];
			}
			_employees[_numOfWorkers - 1] = NULL;
			_numOfWorkers--;
			return;
		}
	}

	cout << "This employee isn't in the database" << endl;
	cout << endl;
}

/* Prints database */
void DataBase::print() const{

	cout << "Employees database:" << endl;
	cout << endl;
	for (int i = 0; i < _numOfWorkers; i++) {
		cout << (*(_employees[i]));
		cout << endl;
	}
}

