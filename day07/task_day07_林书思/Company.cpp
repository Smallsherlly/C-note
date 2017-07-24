#include <iostream>
using namespace std;

class Employee
{
private:
	int m_id;
	string m_name;
	double m_salary;
public:
	Employee(const string& name,int id,int salary):m_id(id),m_name(name),m_salary(salary){}
	double getSalary()
	{
		return m_salary;
	}
};

class Manager:public Employee
{
public:
	Manager(const string& name,int id):Employee(name,id,8000){}
};

class Technician:public Employee
{
public:
	Technician(const string& name,int id,int h):Employee(name,id,h*100){}


};

class Salesman:public Employee
{
public:
	Salesman(const string& name,int id,int m):Employee(name,id,m*0.04){}

};

class Salesmanager:public Employee
{
public:
	Salesmanager(const string& name,int id,int m):Employee(name,id,m*0.05+5000){}

};

int main()
{
	Manager m1("小四",56);
	cout << m1.getSalary() << endl;
	Technician t1("小红",99,22.75*8);
	cout << t1.getSalary() << endl;
	Salesman s1("小张",100,100000);
	Salesmanager s2("小权",23,100000);
	cout << s1.getSalary() << endl;
	cout << s2.getSalary() << endl;
	return 0;	
}
