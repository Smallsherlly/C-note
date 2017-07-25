#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Employee
{
public:
	int m_salary;
public:
	Employee(int salary):m_salary(salary){}
	virtual int salary(){}

};

class GeneraStaff:virtual public Employee
{
public:
	GeneraStaff(int salary):Employee(salary){}
	int salary()
	{
		return m_salary;
	}
};

class Technologist:virtual public Employee
{
public:
	int m_j;
public:
	Technologist(int salary,int j):m_j(j),Employee(salary){}
	int salary()
	{
		return m_j+m_salary;
	}
};

class Saler:virtual public Employee
{
public:
	int m_t;
public:
	Saler(int t,int salary):m_t(t),Employee(salary){}
	int salary()
	{
		return m_t+m_salary;
	}
};

class Manager:virtual public Employee
{
public:
	int m_h;
public:
	Manager(int h,int salary):m_h(h),Employee(salary){}
	int salary()
	{
		return m_h+m_salary;
	}
};

class TechnologistManager:public Technologist,public Manager
{
public:
	TechnologistManager(int j,int h,int s):Manager(j,s),Technologist(s,h),Employee(s){}
	int salary()
	{
		return m_j+m_h+m_salary;
	}

};

class SalerManager:public Saler,public Manager
{
public:
	SalerManager(int t,int h,int s):Saler(t,s),Manager(h,s),Employee(s){}
	int salary()
	{
		return m_t+m_h+m_salary;
	}
};


int main()
{
	int i = 0;
	srand(time(NULL));
	Employee* arr[10] = {};
	for(i=0; i<10; i++)
	{
		switch(rand()%4)
		{
			case 0:
				arr[i] = new GeneraStaff(rand()%1000+500);
				break;
			case 1:
				arr[i] = new Technologist(rand()%1000+500,rand()%1000+500);
				break;
			case 2:
				arr[i] = new TechnologistManager(rand()%600+100,rand()%1000+500,rand()%1000+600);
				break;
			case 3:
				arr[i] = new SalerManager(rand()%700+400,rand()%1000+500,rand()%1000+600);
				break;
		}
		cout << arr[i]->salary() << endl;
	}
	return 0;	
}
