#include <iostream>
#include <cstring>
using namespace std;


class String
{
private:
	char *m_data;
public:
	String(const char* str)
	{
		m_data = new char[strlen(str?str:"")+1];
		strcpy(m_data,str?str:"");
	}
	virtual ~String(void)
	{
		if(NULL != data)
			delete [] m_data;
		m_data = NULL;
	}
	String(const String& that)
	{
		m_data = new char[strlen(that.m_data)+1];
		strcpy(m_data,that.m_data);
	}
	String& operator=(const String& that)
	{
		if(&that != this)
		{
			char* p = new char[strlen(that.m_data)+1];
			delete[] m_data;
			m_data = strcpy(p,that.m_data);
		}
		return *this;
	}
};


int main()
{
	
	return 0;	
}
