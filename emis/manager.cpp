#include "manager.h"
#include <cstring>
#include <iomanip>

Manager::Manager(){}
Manager::Manager(int id,const char* name,const char* psw)
{
	m_id = id;
	strcpy(m_name,name);
	strcpy(m_password,psw);
}

char* Manager::getPsw()
{
	return m_password;
}

int Manager::getId()
{
	return m_id;
}

ostream& operator<<(ostream& os,Manager m)
{
	return os << m.m_id <<setw(6)<< " " << m.m_name <<setw(6)<< " " << m.m_password <<setw(6);
}
