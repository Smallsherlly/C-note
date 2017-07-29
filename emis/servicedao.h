#ifndef _SERVICEDAO_H__
#define _SERVICEDAO_H__

#include <iostream>
#include "department.h"
#include <vector>
using namespace std;

class ServiceDao
{
public:
	//ServiceDao(){}
	virtual ~ServiceDao(){}
	virtual void load(vector<Department>& de)=0;
	virtual void save(vector<Department>& de)=0;

};


#endif  //_SERVICEDAO_H__
