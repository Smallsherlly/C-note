#ifndef _MANAGERDAO_FILE_IMP1_H__
#define _MANAGERDAO_FILE_IMP1_H__
#include "managerdao.h"
class ManagerDaoFileImp1:public ManagerDao
{
public:
	ManagerDaoFileImp1();
	virtual ~ManagerDaoFileImp1();
	void save(vector<Manager>& managers);
	void load(vector<Manager>& managers);
};


#endif //_MANAGERDAO_FILE_IMP1_H__
