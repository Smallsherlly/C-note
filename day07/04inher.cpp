#include <iostream>
using namespace std;

class Person
{
protected:
	string m_name;
	int m_age;
public:
	Person(const string& name="",int age=0)
	{
		cout << "Person" << endl;
		m_name = name;
		m_age = age;
	}	

};

class Student:public Person
{
protected:
	int m_num;
public:
	Student(int num,const string& name="",int age=0):m_num(num),Person(name,age)
	{
		cout << "Student" << endl;	
		cout << m_name << endl;	
		cout << m_age << endl;	
	}
	void show()
	{	
		
	}

};

int main()
{
	Student s(3);
	return 0;	
}
