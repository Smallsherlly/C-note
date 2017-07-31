#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


class Student
{
	string m_name;
	int m_num;
public:
	Student(const string& name,int num)
	{
		m_name = name;
		m_num = num;
	}
	string getName() const
	{
		return m_name;
	}
	int getNum() const
	{
		return m_num;
	}
/*	bool operator=(const Student& s)const
	{
		return m_num < s.m_num;
	}*/
	bool operator<(const Student& s)const
	{
		return m_num < s.m_num;
	}
};

bool cmp(const map<Student,int>::iterator t1,const map<Student,int>::iterator t2)
{
	
	return t1->second < t2->second;
}

int main()
{
	map<Student,int> m;
	m.insert(pair<Student,int>(Student("小明",1),99));
	m[Student("小红",2)] = 100;
	
	Student s1("小白",3);
	Student s2("小猪",4);
	Student s3("小红",5);
	Student s4("小绿",6);

	m[s1] = 98;
	m[s2] = 97;
	m[s3] = 96;
	m[s4] = 90;

	cout << m.size() << endl;
	cout << "---------------------\n";
	typedef map<Student,int>::iterator IT;
	IT it = m.begin();
	cout << "班长候选人提名（姓名，学号）：" << endl;
	while(it!=m.end())
	{
		cout << it->first.getName() << ":" << it->first.getNum() << endl;
		it->second = 0;
		it++;
	}
	it = m.begin();
	while(it!=m.end())
	{
		cout << "请"<<it->first.getName()<<"投票（输入学号）：\n";
		int num = 0;
		cin >> num;
		Student s("班长",num);
		m[s]++;
		it++;
	}
	it = m.begin();
//	sort(m.begin(),m.end(),cmp);
	while(it!=m.end())
	{
		cout << it->first.getName()<<":"<<it->first.getNum() << "同学，获得了"<<it->second<<"张选票\n";
		it++;
	}
	return 0;	
}
