#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Student
{
private:
	string m_name;
	int m_num;
	int m_score;
public:
	Student(const string& name="",int num=0,int score=0)
	{
		m_name = name;
		m_num = num;
		m_score = score;
		cout << "构造函数\n";
	}
	Student(const Student& that)
	{
		m_name = that.m_name;
		m_num = that.m_num;
		m_score = that.m_score;
	
	cout << "拷贝构造\n";
	}
	friend ostream& operator <<(ostream& os,const Student& s);
	friend bool compare(Student ,Student);
	friend bool operator<(const Student& s1,const Student& s2);
	friend bool comNameAsc(const Student stu1,const Student stu2);
	friend bool comNameDesc(const Student stu1,const Student stu2);
	friend bool comNumAsc(const Student stu1,const Student stu2);
	friend bool comNumDesc(const Student stu1,const Student stu2);
	friend bool comScoreAsc(const Student stu1,const Student stu2);
	friend bool comScoreDesc(const Student stu1,const Student stu2);
};

bool operator<(const Student& s1,const Student& s2)
{
	return s1.m_num < s2.m_num;
}

ostream& operator <<(ostream& os,const Student& s)
{
	return os << s.m_name << ":" << s.m_num << ":" << s.m_score << endl;
}
bool comNameAsc(const Student stu1,const Student stu2)
{
	return stu1.m_name < stu2.m_name;
}
bool comNameDesc(const Student stu1,const Student stu2)
{
	return stu1.m_name > stu2.m_name;
}
bool comNumAsc(const Student stu1,const Student stu2)
{
	return stu1.m_num < stu2.m_num;
}
bool comNumDesc(const Student stu1,const Student stu2)
{
	return stu1.m_num > stu2.m_num;
}
bool comScoreAsc(const Student stu1,const Student stu2)
{
	return stu1.m_score < stu2.m_score;
}
bool comScoreDesc(const Student stu1,const Student stu2)
{
	return stu1.m_score > stu2.m_score;
}
void print(vector<Student>& v)
{
	vector<Student>::iterator it = v.begin();
	for(;it!=v.end();it++)
		cout << *it;
}
int main()
{
	vector<Student> v1;//不会调用构造函数
	Student s("张飞",110,98);
	vector<Student> v2(5,s);//拷贝构造
	v2.reserve(10);//拷贝构造
	vector<Student>::iterator it = v2.begin();
	for(it=v2.begin(); it!=v2.end(); it++)
	{
		cout << *it;
	}
	v2.resize(10,s);
	for(it=v2.begin(); it!=v2.end(); it++)
	{
		cout << *it;
	}

	//对象排序 
	v1.push_back(s);
	v1.push_back(Student("关羽",120,100));
	v1.push_back(Student("刘备",119,60));
	sort(v1.begin(),v1.end(),comScoreAsc);
	print(v1);
	return 0;
}	
