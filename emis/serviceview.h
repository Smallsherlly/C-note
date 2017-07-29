#ifndef _SERVICEVIEW_H__
#define _SERVICEVIEW_H__

#include <iostream>
using namespace std;

class ServiceView
{
public:
	virtual ~ServiceView(){}
	virtual void menu()=0;
	virtual bool addDept()=0;
	virtual bool deleteDept()=0;
	virtual void listDept()=0;
	virtual bool addEmp()=0;
	virtual bool deleteEmp()=0;
	virtual bool modifyEmp()=0;
	virtual void listEmp()=0;
	virtual void listAllEmp()=0;

};


#endif// _SERVICEVIEW_H__
