#include <iostream>
using namespace std;

class Array
{
private:
	int *m_data;
	size_t m_len;// 长度
public:
	Array(size_t len=10):m_len(len),m_data(new int[len])// 构造函数
	{
		int i = 0;
		for(i=0; i<len; i++)
		{
			*(m_data+i) = 0;
		}
	}
	Array(const Array& that)// 拷贝构造函数
	{
		int i = 0;
		Array& brr = const_cast<Array&>(that);
		m_len = brr.getSize();
		m_data = new int[m_len];
		for(i=0; i<m_len; i++)
		{
			*(m_data+i) = brr.at(i);
		}
	}
	Array(int *begin,int *end)// 构造函数 根据两个指针之间的元素构造Array
	{
		int i = 0;
		for(i=0; begin+i!=end; i++);
		m_len = i;
		m_data = new int[i];	
		for(i=0; i<m_len; i++)
		{
			*(m_data+i) = *(begin+i);
		}
	}
	~Array(void)// 析构函数
	{
		if(m_data != NULL)
			delete[] m_data;
		m_data = NULL;
	}
	Array& operator=(const Array& that)
	{
		if(&that != this && &that != NULL)
		{
			int i = 0;
			Array& brr = const_cast<Array&>(that);
			if(m_data != NULL)
				delete[] m_data;
			m_len = brr.getSize();
			m_data = new int[m_len];
			for(i=0; i<m_len; i++)
			{
				*(m_data+i) = brr.at(i);
			}
		}
		return *this;
	}
	size_t at(size_t i)// 获得下标为i的元素
	{
		return m_data[i];
	}
	void set(size_t t,int num)// 设置下标为i的元素值为num
	{
		m_data[t] = num;
	}
	int find(int num)// 查找地一个num值的下标，如果没有返回-1
	{
		int i = 0;
		for(i=0; i<m_len; i++)
		{
			if(m_data[i] == num)
				return num = i;
		}
		return -1;
	}
	size_t getSize()// 获得Array的长度
	{
		return m_len;
	}

};


int main()
{
	int brr[10] = {0,1,2,3,4,5,6,7,8,9};
	int *p1 = brr+1;
	int *p2 = brr+8;
	Array arr(p1,p2);
	cout << arr.at(3) << endl;
//	cout << arr.find(4) << endl;
//	cout << arr.getSize() << endl;
	Array crr(arr);
	cout << crr.at(3) << endl;
	Array drr;
	drr = arr;
	cout << drr.at(3) << endl;
	
	return 0;	
}
