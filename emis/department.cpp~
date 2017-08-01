#include "department.h"
#include <iomanip>
Department::Department()
{
	m_nEmpNum = 0;		
}

bool Department::addEmp(int nId,string strName,bool bGender,int nAge)
{
	m_vecEmps.push_back(Employee(nId,strName,bGender,nAge));
	m_nEmpNum++;
}

bool Department::deleteEmp(int id)
{
	vector<Employee>::iterator it = m_vecEmps.begin();
	for(;it!=m_vecEmps.end();it++)
		if((*it).getId()==id)
		{
			m_vecEmps.erase(it);
			m_nEmpNum--;
			return true;
		}
}

vector<Employee> Department::listEmp()
{
	vector<Employee>::iterator it = m_vecEmps.begin();
	for(;it!=m_vecEmps.end();it++)
		cout << *it << endl;
}

bool Department::modifyEmp()
{

}

int Department::getId()
{
	return m_nId;
}
int Department::getEN()
{
	return m_nEmpNum;
}

void Department::addEN()
{
	m_nEmpNum++;
}

void Department::delEN()
{
	m_nEmpNum--;
}


vector<Employee>& Department::getEmployee()
{
	return m_vecEmps;
}

ostream& operator<<(ostream& os,const Department& de)
{
	return os << de.m_nId <<setw(6)<< " " << de.m_strName <<setw(6)<< " " << de.m_nEmpNum <<setw(6)<< " ";
}

istream& operator>>(istream& is,Department& de)
{
	return is >> de.m_nId >> de.m_strName >> de.m_nEmpNum;
}
