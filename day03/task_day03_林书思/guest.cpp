#include "guest.h"
using namespace HM;

Guest::Guest(const string& name)
{
	m_name = name;
}

string& Guest::getName()
{
	return m_name;
}

void Guest::setName(const string& name)
{
	m_name = name;
}

