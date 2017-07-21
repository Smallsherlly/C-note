#include <iostream>
using namespace std;

class Student;

class Teacher
{
private:
	string m_name;
public:
	Teacher(const string& name):m_name(name){}
	void teaching(Student s);
};

class Student
{
private:
	int m_num;
	string m_name;
	int m_age;
public:
	Student (int num,const string& name,int age)
	{
		m_num = num;
		m_name = name;
		m_age = age;
	}
	friend void Teacher::teaching(Student s);
};

void Teacher::teaching(Student s)
{
	cout << m_name <<"老师，正在教" << s.m_name << endl;
}



int main()
{
	Teacher t("大神");
	Student s(56,"小红",7);
	t.teaching(s);
	return 0;	
}
