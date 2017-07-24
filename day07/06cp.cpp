//
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
protected:
	char* m_name;
	int m_age;
public:
//	Person(){}
	Person(const char* name,int age)
	{
		m_name = new char[strlen(name)+1];
		strcpy(m_name,name);
		m_age = age;
	}
	Person(const Person& that)
	{
		m_name = new char[strlen(that.m_name)+1];
		m_age = that.m_age;
	}
	Person& operator=(const Person& that)
	{
		if(&that != this)
		{
			char* p = new char[strlen(that.m_name)+1];
			delete[] m_name;
			m_name = strcpy(p,that.m_name);
			m_age = that.m_age;
		}
		return *this;
	}
	~Person(void)
	{
		if(m_name != NULL)
		{
			delete[] m_name;
			m_name = NULL;
		}
	}
};

class Student:public Person
{
private:
	int m_num;
	char* m_address;
public:
//	Student(){}
	Student(const char* name,int age,int num,const char* address):Person(name,age)
	{
		m_address = new char[strlen(address)+1];
		strcpy(m_address,address);
		m_num = num;
	}
	Student(const Student& that):Person(that)
	{
		m_address = new char[strlen(that.m_name)+1];
		strcpy(m_address,that.m_address);
		m_num = that.m_num;
	}
	Student& operator=(const Student& that)
	{
		if(&that != this)
		{	
			Person::operator=(that);
			char* p = new char[strlen(that.m_address)+1];
			delete[] m_address;
			m_address = strcpy(p,that.m_address);
			m_num = that.m_num;
		}
		return *this;
	}
	~Student(void)
	{
		if(m_address != NULL)
		{
			delete[] m_address;
		}
		m_address = NULL;
	}
	void show()
	{
		cout << m_name << ":" << m_age << ":" << m_num << ":" << m_address << endl;
	}
};

int main()
{
	Student s1("张三",33,110,"武当");
	s1.show();
	Student s2 = s1;
	s2.show();
	Student s3;
	s3.show();
	s3 = s1;
	s3.show();
	
	return 0;	
}
