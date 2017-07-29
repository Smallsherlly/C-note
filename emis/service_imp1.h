#ifndef _SERVICE_IMP1_H__
#define _SERVICE_IMP1_H__

#include <iostream>
#include <vector>
#include "department.h"
#include "service.h"
#include "servicedao.h"
#include "servicedao_file_imp1.h"
#include "tools.h"
using namespace std;

class ServiceImp1:public Service
{
private:
	ServiceDao* m_pDao;
	vector<Department> m_vecDepts;
public:
	ServiceImp1();
	virtual ~ServiceImp1();
	virtual bool addDept(const string& name);
	virtual bool deleteDept(int id);
	virtual vector<Department> listDept();
	virtual bool addEmp(int,string,bool,int);
	virtual bool deleteEmp(int id);
	virtual bool modifyEmp(int id,string name,bool sex,int age);
	virtual vector<Employee> listEmp(int id);
	virtual vector<Department> listAllEmp();

};


#endif// _SERVICE_IMP1_H__
