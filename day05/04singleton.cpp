#include <iostream>
using namespace std;

class SingleTon
{
private:
	SingleTon(){}
	SingleTon(const SingleTon& that){}
	static SingleTon *m_instance;
	static pthread_mutex_t m_lock;
public:
	static SingleTon& getInstance()
	{
		if(m_instance == NULL)
		{
			pthread_mutex_lock(&m_lock);
			if(m_instance == NULL)
			{
				m_instance = new SingleTon;
			}
			pthread_mutex_unlock(&m_lock);
		}
		return *m_instance;
	}
	~SingleTon(void)
	{
		if(m_instance != NULL)
		{
			pthread_mutex_lock(&m_lock);
			if(m_instance != NULL)
				delete m_instance;
			pthread_mutex_unlock(&m_lock);
		}
	}

};

SingleTon* SingleTon::m_instance = NULL;
pthread_mutex_t SingleTon::m_lock = PTHREAD_MUTEX_INITIALIZER;

int main()
{
	SingleTon& s1 = SingleTon::getInstance();
	SingleTon& s2 = SingleTon::getInstance();
	cout << &s1 << endl;	
	cout << &s2 << endl;	
	return 0;	
}
