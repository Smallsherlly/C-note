#ifndef _DEPARTMENT_H__
#define _DEPARTMENT_H__

#include <iostream>
#include <vector>
#include "employee.h"

using namespace std;

class Department
{
private:
	int m_nId;
	string m_strName;
	int m_nEmpNum;
	vector<Employee> m_vecEmps;
public:
	Department();
	Department(int id,const string& name):m_nId(id),m_strName(name),m_nEmpNum(0){}
	bool addEmp(int nId,string strName,bool bGender,int nAge);
	bool deleteEmp(int id);
	vector<Employee> listEmp();
	bool modifyEmp();
	int getId();
	int getEN();
	void addEN();
	void delEN();
	vector<Employee>& getEmployee();
	friend ostream& operator<<(ostream& os,const Department& de);
	friend istream& operator>>(istream& is,Department& de);
};


#endif // _DEPARTMENT_H__
