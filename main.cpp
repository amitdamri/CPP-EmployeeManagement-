#include "Employee.h"
#include "DataBase.h"

int main() {

	DataBase dataBase;
	dataBase.addEmployee(new Employee((char*)"Sharon",11,10000));
	dataBase.addEmployee(new Employee((char*)"Yael",11,11000));
	dataBase.addEmployee(new Employee((char*)"Yael",12,20000));
	dataBase.addEmployee(new Employee((char*)"Barak",10,11000));
	dataBase.print();
	dataBase.removeEmployee(1);
	dataBase.removeEmployee(11);
	dataBase.print();


	dataBase.print();
	Employee *yael = dataBase.getEmployee(12);
	Employee *barak = dataBase.getEmployee(10);


	cout<<"Cost party for Barak: "<< barak->planOfficeParty() << "\n" <<endl;

	if(*barak>*yael)
	{
		cout<<"Barak's salary is higher than Yael's \n"<<endl;
	}

	double salaryBefore =((*barak)++).getSalary();
	cout<< "Salary before:"<< salaryBefore <<"\n"<<endl;
	cout <<(*barak)<<endl;

	*barak+*yael;
	*barak += *yael;


	dataBase.print();

	if(*barak>*yael)
	{
		cout<<"Barak's salary is higher than Yael's \n"<<endl;
	}

	return 0;

}
