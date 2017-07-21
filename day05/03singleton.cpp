#include <iostream>
using namespace std;

class SingleTon
{
private:
	SingleTon(){}
	SingleTon(const SingleTon& that){}
	static SingleTon * m_singleton;
public:
	static SingleTon& getInstance()
	{
		if(m_singleton == NULL)
		{
			m_singleton = new SingleTon;
		}
		return *m_singleton;
	}
	~SingleTon(void)
	{
		if(m_singleton!=NULL)
		{
			delete m_singleton;
			m_singleton = NULL;
		}
	}
};

SingleTon* SingleTon::m_singleton = NULL; //没有实例化

int main()
{
	SingleTon& s1 = SingleTon::getInstance(); 
	SingleTon& s2 = SingleTon::getInstance();
	cout << &s1 << endl;
	cout << &s2 << endl;
	return 0;	
}
