#include <iostream>
using namespace std;

class UnderFlowError
{
private:
	string err;
public:
	UnderFlowError(const char* str="过小越界"):err(str){}
	const char* getErr()
	{
		return err.c_str();
	}
};

class OverFlowError
{
private:
	string err;
public:
	OverFlowError(const char* str="过大越界"):err(str){}
	const char* getErr()
	{
		return err.c_str();
	}
};
class Stack
{
private:
	int arr[10];
public:
	Stack(){}
	void insert(int data,int index)
	{
		if(index < 0)
		{
			throw UnderFlowError();
		}
		if(index >= 10)
		{
			throw OverFlowError();
		}

	}

};


int main()
{
	Stack s;
	try
	{
		s.insert(100,11);
	}catch(int& i)
	{
		if(i == -1)
		{
			cout << "索引值小于0\n";
		}
		else if(i == -2)
		{
			cout << "索引值过大越界\n";
		}
	}catch(UnderFlowError& err)
	{
		cout << err.getErr() << endl;
	}catch(OverFlowError& err)
	{
		cout << err.getErr() << endl;
	}
	return 0;
}
