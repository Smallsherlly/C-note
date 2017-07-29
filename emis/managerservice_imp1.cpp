#include "managerservice_imp1.h"
#include <cstring>

ManagerServiceImp1::ManagerServiceImp1()
{
	m_dao = new ManagerDaoFileImp1();
	m_dao->load(m_managers);
}
bool ManagerServiceImp1::addManager(int id,const char* name,const char* psw)
{
	m_managers.push_back(Manager(id,name,psw));
}
vector<Manager> ManagerServiceImp1::listManager()
{
	return m_managers;
}
bool ManagerServiceImp1::deleteManager(int id)
{
	vector<Manager>::iterator vs = m_managers.begin();
	for(;(*vs).getId()!=id;vs++);
		m_managers.erase(vs);
}

bool ManagerServiceImp1::login(int id,const char* psw)
{
	vector<Manager>::iterator vs = m_managers.begin();
	for(;vs!=m_managers.end();vs++)
	{
		if((*vs).getId()==id)
		{
			if(!strcmp((*vs).getPsw(),psw))
				return true;
		}
	}
	return false;
}

ManagerServiceImp1::~ManagerServiceImp1(void)
{
	m_dao->save(m_managers);
	if(m_dao!=NULL)
		delete m_dao;
	m_dao = NULL;
}



