#ifndef _MANAGERVIEW_CONSOLE_IMP1_H__
#define _MANAGERVIEW_CONSOLE_IMP1_H__
#include "managerservice_imp1.h"
#include "serviceview_console_imp1.h"
#include "serviceview.h"
#include "managerview.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class ManagerviewConsoleImp1:public ManagerView
{
private:
	ManagerService* m_service;
	ServiceView* m_serviceview;
public:
	ManagerviewConsoleImp1();
	void show();
	virtual void menu();
	virtual void add();
	virtual void del();
	virtual void list();
	virtual ~ManagerviewConsoleImp1();
};



#endif // _MANAGERVIEW_CONSOLE_IMP1_H__
