#include <iostream>
using namespace std;

template<typename T>
class vector
{
private:
	T *m_p;
	size_t m_size;
	size_t m_cap;
public:
	vector()
	{
		m_p = NULL;
		m_size = 0;
		m_cap = 0;
	}
	vector(size_t size)
	{
		m_size = size;
		m_cap = size;
	}
	vector(const vector& v)
	{
		m_p = new T[v.m_size];
		m_size = v.m_size;
		m_cap = v.m_cap;
		for(int i=0; i<m_size; i++)
		{
			m_p[i] = v.m_p[i];
		}
	}
	vector(size_t size,const T& obj)
	{
		m_p = new T[size];
		for(int i=0; i<size; i++)
		{
			m_p[i] = obj;
		}
		m_size = size;
		m_cap = size;
	}
	~vector(void)
	{
		if(m_p != NULL)
			delete[] m_p;
		m_p = NULL;
		m_size = 0;
		m_cap = 0;
	}
	size_t size()
	{
		return m_size;
	}
	void resize(size_t size,const T& obj)
	{
		if(size > m_size)
		{
			if(m_cap >= size)
			{
				for(int i=0; i<size-m_size; i++)
				{
					m_p[m_size+i] = obj;
				}
				m_size = size;
			}else
			{
				T *p = new T[size];
				for(size_t i=0; i<size; i++)
				{
					if(i < m_size)
					{
						p[i] = m_p[i];
					}else
					{
						p[i] = obj;
					}
				}
				m_size = size;
				m_cap = size;
			}
		}else
		{
			for(size_t i=size; i<m_size; i++)
			{
				delete m_p[i];
			}
			m_size = size;
		}
	}
	void reserve(size_t cap)
	{
		T *p = new T[cap];
		if(m_size <cap)
		{
			for(int i=0; i<m_size;i++)
			{
				p[i] = m_p[i];
			}
		}else
		{
			for(int i=0; i<cap; i++)
			{
				p[i] = m_p[i];
			}
			m_size = cap;
		}
		m_cap = cap;
		delete[] m_p;
		m_p = p;
	}

	T& operator[](size_t index)
	{
		return m_p[index];
	}

	void push_back(T data)
	{
		T *p = new T[m_size+1];
		int i = 0;
		for(i=0; i<m_size; i++)
		{
			p[i] = m_p[i];
		}
		p[i] = data;
		m_size++;
		swap(m_p,p);
	}

	bool empty()
	{
		return m_size;
	}

	void clear()
	{
		~vector();
	}

	T& at(int index)
	{
		if(index >= m_size)
		{
			throw "too big";
		}
		return m_p[index];
	}
	T& front()
	{
		return m_p[0];
	}
	T back()
	{
		return m_p[m_size-1];
	}
//	friend class Iterator;
	class Iterator
	{
	private:
		T *p;
	public:
		Iterator()
		{
			p = m_p;
		}
		Iterator(T *fp)
		{
			p = fp;
		}
		Iterator& operator++()
		{
			p++;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator temp(*this);
			p++;
			return temp;
		}
		T& operator*()
		{
			return *p;
		}
		bool operator!=(const Iterator& o)
		{
			return p!=o.p;
		}	
	};
	Iterator begin()
	{
		return Iterator(m_p);
	}
	Iterator end()
	{
		return Iterator(m_p+m_size);
	}
};


int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);
	cout << v.at(0) << endl;
	cout << v.at(1) << endl;
	cout << v.back() << endl;
	vector<int>::Iterator it = v.begin();
	cout << *it << endl;
	it++;
	cout << *it << endl;
	*it = 99;
	cout << *it << endl;

	return 0;
}
