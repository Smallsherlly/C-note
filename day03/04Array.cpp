#include <iostream>
using namespace std;

class Array
{
	size_t m_len;
	int* m_data;
public:
	Array(int data,size_t len = 0):m_data(&data),m_len(++len)
	{

	}
	void show()
	{
		int i = 0;
		cout << m_len << endl;
		for(; i<m_len; i++)
		{
			cout << m_data[i] << endl;
		}

	}

};


int main()
{
	Array arr(3);
	arr.show();
	
	return 0;
}
