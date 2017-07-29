#ifndef _MANAGERVSERVICE_IMP1_H__
#define _MANAGERVSERVICE_IMP1_H__

#include <vector>
#include "managerservice.h"
#include "managerdao.h"
#include "managerdao_file_imp1.h"

using namespace std;

class ManagerServiceImp1:public ManagerService
{
private:
	vector<Manager> m_managers;
	ManagerDao* m_dao;
public:
	ManagerServiceImp1();
	virtual bool login(int id,const char* psw);
	virtual ~ManagerServiceImp1(void);
	virtual bool addManager(int id,const char* name,const char* psw);
	virtual vector<Manager> listManager();
	virtual bool deleteManager(int id);
};


#endif //_MANAGERSERVICE_IMP1_H__
