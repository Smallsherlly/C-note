#include "managerservice_imp1.h"

ManagerServiceImp1::ManagerServiceImp1()
{
	m_dao = new ManagerDaoFileImp1();
	m_dao->load(m_managers);
}
bool ManagerServiceImp1::addManager(int id,const char* name,const char* psw)
{
	m_managers.push_back(Manager(id,name,psw));
	m_dao->save(m_managers);
}
vector<Manager> ManagerServiceImp1::listManager()
{
	vector<Manager>::iterator vs = m_managers.begin();
	for(; vs!=m_managers.end(); vs++)
	{
		cout << *vs << endl;
	}
	return m_managers;
}
bool ManagerServiceImp1::deleteManager(int id)
{
	vector<Manager>::iterator vs = m_managers.begin();
	for(;(*vs).getId()!=id;vs++);
		m_managers.erase(vs);
	m_dao->save(m_managers);
}



