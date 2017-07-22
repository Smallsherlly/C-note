//全局函数定义类的操作符
#include <iostream>
using namespace std;

class complex
{
private:
	int m_s;
	int m_x;
public:
	complex(int s,int x):m_s(s),m_x(x){}
	void show()
	{
		cout << m_s << endl;
		cout << m_s << endl;
	}
friend complex operator++(complex& that,int);
friend complex& operator++(complex& that);
friend complex& operator--(complex& that);
friend complex operator--(complex& that,int);
friend complex& operator+=(complex& pp,complex& that);
friend complex& operator-=(complex& pp,complex& that);
friend ostream& operator<<(ostream& os,const complex& c);
friend istream& operator>>(istream& is,complex& c);
};



complex operator++(complex& that,int)
{
	complex temp(that.m_s,that.m_x);
	that.m_s++;
	return temp;
}
complex& operator++(complex& that)
{
	that.m_s++;
	return that;
}
complex& operator--(complex& that)
{
	that.m_s++;
	return that;
}
complex operator--(complex& that,int)
{
	complex temp = that;
	that.m_s++;
	return temp;
}
complex& operator+=(complex& pp,complex& that)
{
	pp.m_s = pp.m_s+that.m_s;
	pp.m_x = pp.m_x+that.m_x;
	return pp;
}
complex& operator-=(complex& pp,complex& that)
{
	pp.m_s = pp.m_s-that.m_s;
	pp.m_x = pp.m_x-that.m_x;
	return pp;
}
ostream& operator<<(ostream& os,const complex& c)
{
	return os << c.m_s << "+" << c.m_x << "i" << endl;
}
istream& operator>>(istream& is,complex& c)
{
	return is>> c.m_s >> c.m_x;
}

int main()
{
	complex c1(4,6);
	c1.show();
	complex c2(7,7);
	
	(c1++).show();
	cout << c1++;
	cout << c1;
	cin >> c1;
	cout << c1;
	return 0;	
}



