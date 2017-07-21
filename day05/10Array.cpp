#include <iostream>
using namespace std;

class Array
{
private:
	int *m_p;
	size_t m_len;
public:
	Array(size_t len = 10)
	{
		m_p = new int[len];
		m_len = len;
	}
	Array(const Array& that)
	{
		m_p = new int[that.m_len];
		m_len = that.m_len;
		int i = 0;
		for(i=0; i<m_len; i++)
		{
			//*(m_p+i) = *(that.m_p+i);
			//m_p[i] = (that.m_p)[i];
			i[m_p] = i[that.m_p];
		}		
	}
	Array& operator=(const Array& that)
	{
		if(&that != this)
		{
			int *p = new int[that.m_len];
			m_len = that.m_len;
			int i = 0;
			for(i=0; i<m_len; i++)
			{
				p[i] = (that.m_p)[i];
			}
			delete[] m_p;// 前面部分可能会出错，如果出错，要保留数据
			m_p = p;
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
	}
	Array(int *begin,int *end)
	{
		int *big = begin>end?begin:end;	
		int *lit = begin>end?end:begin;
		m_len = big - lit + 1;
		int* p = new int[m_len];
		for(;begin<=end;)
		{
			*p++ = *begin++;
		}
		p = p - m_len;
		m_p = p;
	}
	void show()
	{
		int i = 0;
		for(i=0; i<m_len; i++)
		{
			cout << m_p[i] << "  ";
		}
		cout << endl;
	}
};

int main()
{
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	Array a1(&arr[0],&arr[9]);
	a1.show();
	return 0;	
}
