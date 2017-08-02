#include <iostream>
#include <list>
#include <deque>
#include <queue>
using namespace std;

class Student
{
private:
	string m_name;
	int m_age;
	int m_num;
	int m_score;
public:
	Student(){}
	Student(const string& name,int age,int num,int score)
	{
		m_name = name;
		m_age = age;
		m_num = num;
		m_score = score;
	}
	bool operator<(const Student& o)const
	{
		if(m_score == o.m_score)
			return m_age < o.m_age;
		else
			return m_score < o.m_score;
	}
	friend ostream& operator<<(ostream& os,const Student& s);
};

ostream& operator<<(ostream& os,const Student& s)
{
	return os << s.m_name << " " << s.m_age << " " << s.m_num << " " << s.m_score << endl;
}

template<typename IT>
void print(IT begin,IT end)
{
	while(begin!=end)
		cout << *begin++ << endl;
}

int main()
{
	list<Student> l1;
	list<Student> l2;
	list<Student> l3;
	
	l1.push_back(Student("撒的",33,110,98));
	l1.push_back(Student("关羽",30,120,99));
	l1.push_back(Student("刘备",34,119,100));

	l2.push_back(Student("小贝",19,111,60));
	l2.push_back(Student("小绿",3,121,40));
	l3.push_back(Student("小红",4,122,10));
	l3.push_back(Student("小发",18,142,50));

	l1.merge(l2);
	l1.merge(l3);

	print(l1.begin(),l1.end());
	l1.sort();
	print(l1.begin(),l1.end());
//	cout << *(l1.end()) << endl;

	priority_queue<Student> p;
	p.push(Student("ming",7,1,99));
	p.push(Student("hong",7,2,97));
	p.push(Student("bai",7,3,94));
	p.push(Student("li",7,4,98));
	while(!p.empty())
	{
		cout << p.top() << endl;
		p.pop();
	}
	return 0;	
}
