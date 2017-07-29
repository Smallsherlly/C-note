#ifndef _MANAGERSERVICE_H__
#define _MANAGERSERVICE_H__
#include <vector>
#include "manager.h"
using namespace std;

class ManagerService
{
public:
	virtual ~ManagerService(){};
	virtual bool login(int id,const char* psw)=0;
	virtual bool addManager(int,const char*,const char*)=0;
	virtual vector<Manager> listManager()=0;
	virtual bool deleteManager(int id)=0;
};


#endif //_MANAGERSERVICE_H__
