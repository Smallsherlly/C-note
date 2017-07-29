#include <iomanip>
#include "employee.h"

Employee::Employee(int nId,string strName,bool bGender,int nAge)
{
	m_nId = nId;
	m_strName = strName;
	m_bGender = bGender;
	m_nAge = nAge;
}

int Employee::getId()
{
	return m_nId;
}

void Employee::changeInfo(string name,bool sex,int age)
{
	m_strName = name;
	m_bGender = sex;
	m_nAge = age;
}

ostream& operator<<(ostream& os,const Employee& e)
{
	return os << e.m_nId <<setw(6)<< " " << e.m_strName <<setw(6)<< " " << e.m_bGender <<setw(6)<< " " <<e.m_nAge <<setw(6)<< " ";
}

istream& operator>>(istream& is,Employee& e)
{
	return is >> e.m_nId >> e.m_strName >> e.m_bGender >> e.m_nAge;
}
