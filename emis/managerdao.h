#ifndef _MANAGERDAO_H__
#define _MANAGERDAO_H__

#include <iostream>
#include <vector>
#include "manager.h"

using namespace std;
class ManagerDao
{
public:
	ManagerDao(){}
	virtual ~ManagerDao(){};
	virtual void load(vector<Manager>& managers)=0;
	virtual void save(vector<Manager>& managers)=0;


};



#endif //_MANAGERDAO_H__
