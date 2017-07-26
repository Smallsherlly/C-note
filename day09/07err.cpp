#include <iostream>
using namespace std;

void func(int n)
{
	cout << "++++++++++" << endl;
	if(n<0)
	{
		throw -1;
	}
	cout << "----------" << endl;

}

int main()
{
	try{
		cout << "***********" << endl;
		func(-1);
		cout << "##########" << endl;
	}catch(int &d)
	{
		cout << "捕获异常：" << d << endl;
	}

}
