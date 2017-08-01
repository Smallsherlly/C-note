#include <iostream>
#include <stdexcept>
using namespace std;

template<typename T>
class Array
{
private:
	T *m_p;
	size_t m_len;
public:
	Array(size_t len)
	{
		m_p = new T[len];
		m_len = len;
	}
	Array(const Array& other)
	{
		m_p = new T[other.m_len];
		m_len = other.m_len;
		for(size_t i=0; i<m_len; i++)
		{
			m_p[i] = other.m_p[i];
		}
	}
	Array& operator=(const Array& other)
	{
		if(&other != this)
		{
			Array arr(other);
			swap(m_p,arr.m_p);
		}
		return *this;
	}
	~Array(void)
	{
		if(m_p != NULL)
		{
			delete[] m_p;
		}
		m_p = NULL;
		m_len = 0;
	}
	T& operator[](size_t index)
	{
		if(index >= m_len)
		{
			throw overflow_error("over");
		}
		return m_p[index];
	}
	size_t size()
	{
		return m_len;
	}
};

int main()
{
//	int a[4] = {3,5,6,7};
	try
	{
		Array<int> a(10);
		for(size_t i=0; i<a.size(); i++)
		{
			a[i] = i;
		}
		for(size_t i=0; i<a.size(); i++)
		{
			cout << a[i] << endl;
		}
	}catch(string& err)
	{
		cout << err << endl;
	}
	return 0;
}
