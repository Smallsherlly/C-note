#ifndef _MANAGER_H__
#define _MANAGER_H__

#include <iostream>
using namespace std;

class Manager
{
private:
	int m_id;
	char m_name[20];
	char m_password[20];
public:
	Manager();
	Manager(int id,const char* name,const char* psw);
	int getId();
	char* getPsw();
	friend ostream& operator<<(ostream& os,Manager m);
};


#endif //_MANAGER_H__
