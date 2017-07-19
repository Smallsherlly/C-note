#include <iostream>
using namespace std;

typedef bool(*Action)(void*);

class Timer
{
	unsigned int second;
	Action action;
public:
	Timer(unsigned int s)
	{
		second = s;
	}
	void begin()
	{
		sleep(second);
	}

	void setAction(Action a)
	{
		action = a;
		begin();
		action(&second);
	}

};

bool func(void* se)
{
	unsigned int* s = static_cast<unsigned int*>(se);
	cout << *s << "秒，时间已到！" << endl;
}

int main()
{
	int t = 0;
	cout << "请输入定时秒数" << endl;
	cin >> t;
	cout << "开始计时！" << endl;
	Timer time(t);
	time.setAction(func);
	return 0;	
}
