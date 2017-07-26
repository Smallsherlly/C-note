#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	string m_name;
	int m_age;
public:
	Person(const string& name="",int age=0)
	{
		m_name = name;
		m_age = age;
	}
	virtual ~Person()
	{
		cout << "~Person\n";

	}
};

class Student:public Person
{
private:
	char * m_address;
	int m_num;
public:
	Student(const string& name,int age,const char* address,int num):Person(name,age)
	{
		m_address = new char[strlen(address?address:"")+1];
		strcpy(m_address,address?address:"");
	}
	~Student()
	{
		cout << "~Student" << endl;
		if(m_address != NULL)
		{
			delete[] m_address;
		}
		m_address = NULL;
	}

};

int main()
{
	Person* pa = new Student("小亮",14,"杭州西湖",119);
	delete pa;
	return 0;
}
