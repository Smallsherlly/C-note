#ifndef  _EMPLOYEE_H__
#define  _EMPLOYEE_H__

#include <iostream>
using namespace std;

class Employee
{
private:
	int m_nId;
	string m_strName;
	bool m_bGender;
	int m_nAge;
public:
	Employee(){}
	Employee(int nId,string strName,bool bGender,int nAge);
	int getId();
	void changeInfo(string name,bool sex,int age);
	friend ostream& operator<<(ostream& os,const Employee& e);
	friend istream& operator>>(istream& is,Employee& e);
};

#endif // _EMPLOYEE_H__
