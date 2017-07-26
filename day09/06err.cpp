#include <iostream>
using namespace std;

class Array
{
private:
	int* m_data;
	int m_len;
public:
	Array(size_t len)
	{
		m_data = new int[len];
		m_len = len;
	}
	void setData(int data,int index)
	{
		if(index < 0)
		{
			//return;
			throw string("索引值小于0");
		}
		else if(index >= m_len)
		{
			//return;
			throw string("索引值过大");
		}
		m_data[index] = data;
	}
	int getData(int index)
	{
		return m_data[index];
	}
	virtual ~Array()
	{
		if(m_data != NULL)
		{
			delete[] m_data;
		}
		m_data = NULL;
	}

};

int main()
{
	Array arr(10);
	int i = 0;
	for(i=0; i<10; i++)
	{
		try
		{
			arr.setData(i,i);
		}catch(string &err)
		{
			cout << err << endl;
		}
	}
	for(i=0; i<10; i++)
	{
		cout << arr.getData(i) << " ";
	}
	cout << endl;
	try
	{
		arr.setData(100,100000000);
	}catch(string& err)
	{
		cout << err << endl;
	}
	return 0;	
}
