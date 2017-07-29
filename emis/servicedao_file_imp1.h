#ifndef _SERVICEDAO_FILE_IMP1_H__
#define _SERVICEDAO_FILE_IMP1_H__

#include "servicedao.h"

class ServiceDaoFileImp1:public ServiceDao
{
public:
	ServiceDaoFileImp1(){}
	~ServiceDaoFileImp1(){}
	virtual void load(vector<Department>& de);
	virtual void save(vector<Department>& de);
};


#endif  //_SERVICEDAO_FILE_IMP1_H__
