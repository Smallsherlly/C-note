#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
	char * m_name;
	char * m_address;
public:
	Student(const char* name,const char* address)
	{
		try
		{
			m_name = new char[strlen(name?name:"")+1];
		}catch(bad_alloc& e)
		{
			throw e;//不处理，直接抛出
		}
		try
		{
			throw bad_alloc();
			m_address = new char[strlen(address?address:"")+1];
		}catch(bad_alloc& e)
		{
			delete[] m_name;//得手动释放已经分配好的内存
			throw e;
		}
	}
	~Student()
	{
		try
		{
			if(m_name != NULL)
			{
				delete [] m_name;
			}
		}catch(...)
		{
			//捕获到异常后自行处理，不外抛，继续释放资源
		}
		m_name = NULL;
		try
		{
			if(m_address != NULL)
			{
				delete [] m_address;
			}
		}catch(...)
		{

		}
		m_address = NULL;
	}
};

int main()
{
	try
	{
		Student("dad","dasd");

	}catch(bad_alloc& e)
	{
		cout << "内存分配失败" << endl;
	}
	return 0;
}
