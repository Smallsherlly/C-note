#ifndef _SERVICEVIEW_CONSOLE_IMP1_H__
#define _SERVICEVIEW_CONSOLE_IMP1_H__

#include "serviceview.h"
#include "service_imp1.h"
#include "service.h"
#include "tools.h"

class ServiceViewConsoleImp1:public ServiceView
{
private:
	Service* m_pService;	
public:
	ServiceViewConsoleImp1();
	~ServiceViewConsoleImp1();
	void show();
	virtual void menu();
	virtual bool addDept();
	virtual bool deleteDept();
	virtual void listDept();
	virtual bool addEmp();
	virtual bool deleteEmp();
	virtual bool modifyEmp();
	virtual void listEmp();
	virtual void listAllEmp();

};


#endif// _SERVICEVIEW_CONSOLE_IMP1_H__
