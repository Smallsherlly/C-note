#include "service_imp1.h"

ServiceImp1::ServiceImp1()
{
	m_pDao = new ServiceDaoFileImp1();
	m_pDao->load(m_vecDepts);
}

ServiceImp1::~ServiceImp1()
{
	m_pDao->save(m_vecDepts);
	if(m_pDao!=NULL)
		delete m_pDao;
	m_pDao = NULL;
}

bool ServiceImp1::addDept(const string& name)
{
	m_vecDepts.push_back(Department(generator_id(),name));
}

bool ServiceImp1::deleteDept(int id)
{
	vector<Department>::iterator it = m_vecDepts.begin();
	for(;it!=m_vecDepts.end();it++)
		if((*it).getId()==id)
		{
			m_vecDepts.erase(it);
			break;
		}
}

vector<Department> ServiceImp1::listDept()
{
	return m_vecDepts;
}

bool ServiceImp1::addEmp(int id,string name,bool sex,int age)
{
	vector<Department>::iterator it = m_vecDepts.begin();
	for(;it!=m_vecDepts.end();it++)
		if((*it).getId()==id)
		{
			(*it).getEmployee().push_back(Employee(generator_id(),name,sex,age));
			(*it).addEN();
			break;
		}
}

bool ServiceImp1::deleteEmp(int id)
{
	vector<Department>& de = m_vecDepts;
	vector<Department>::iterator it = de.begin();
	for(;it != de.end();it++)
	{
		vector<Employee>& emp = (*it).getEmployee();
		vector<Employee>::iterator pt = emp.begin();
		for(;pt!=emp.end();pt++)
		{
			if((*pt).getId()==id)
			{
				emp.erase(pt);
				(*it).delEN();
			}
		}
	}
}

bool ServiceImp1::modifyEmp(int id,string name,bool sex,int age)
{
	vector<Department>& de = m_vecDepts;
	vector<Department>::iterator it = de.begin();
	for(;it != de.end();it++)
	{
		vector<Employee>& emp = (*it).getEmployee();
		vector<Employee>::iterator pt = emp.begin();
		for(;pt!=emp.end();pt++)
		{
			if((*pt).getId()==id)
			{
				(*pt).changeInfo(name,sex,age);
				return true;
			}
		}
	}
	return false;
}

vector<Employee> ServiceImp1::listEmp(int id)
{
	vector<Department>::iterator it = m_vecDepts.begin();
	for(;it!=m_vecDepts.end();it++)
		if((*it).getId()==id)
		{
			return (*it).getEmployee();
		}
	vector<Employee> nul;
	return nul;
}


vector<Department> ServiceImp1::listAllEmp()
{
	return m_vecDepts;
}

