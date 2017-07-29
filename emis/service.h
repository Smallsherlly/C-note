#ifndef _SERVICE_H__
#define _SERVICE_H__

#include <iostream>
#include <vector>
#include "department.h"
using namespace std;

class Service
{
public:
	virtual ~Service(){}
	virtual bool addDept(const string& name)=0;
	virtual bool deleteDept(int id)=0;
	virtual vector<Department> listDept()=0;
	virtual bool addEmp(int id,string name,bool sex,int age)=0;
	virtual bool deleteEmp(int id)=0;
	virtual bool modifyEmp(int id,string name,bool sex,int age)=0;
	virtual vector<Employee> listEmp(int id)=0;
	virtual vector<Department> listAllEmp()=0;

};


#endif// _SERVICE_H__
