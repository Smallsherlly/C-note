#include <iostream>
using namespace std;

//懒汉模式，对象已经存在
class ChairMan
{
private:
	string m_name;
	static ChairMan m_chairman;
	ChairMan(string name):m_name(name){}
	ChairMan(const ChairMan& that){}
public:
	static ChairMan& getInstance()
	{
		return m_chairman;
	}
	const string& getName()
	{
		return m_name;
	}
	void setName(const string& name)
	{
		m_name = name;
	}

};
string str("林书思");
ChairMan ChairMan::m_chairman(str);
class SingleTon
{
private:
	static SingleTon m_singleton;
	SingleTon(){};
	SingleTon(const SingleTon& that){}
public:
	static SingleTon& getInstance()
	{
		return m_singleton;
	}

	
};

SingleTon SingleTon::m_singleton;

int main()
{
//	SingleTon s;
//	SingleTon *s = new SingleTon();
	SingleTon& s = SingleTon::getInstance();
	ChairMan& c = ChairMan::getInstance();
	cout << "我们伟大的国家主席：\n";
	cout << c.getName() << endl;
	c.setName("习近平");
	cout << c.getName() << endl;
	return 0;	
}
