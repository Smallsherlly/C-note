#include <iostream>
using namespace std;

class Phone
{
private:
	string m_num;
public:
	Phone(const string& num):m_num(num){}
	void calling()
	{
		cout << "I am calling you baby～" << endl;
	}
	void show()
	{
		cout << "我是一部手机\n";
	}
};

class Computer
{
public:
	void coding()
	{
		cout << "电脑可以编程。。。" << endl;
	}
	void show()
	{
		cout << "我是一台电脑\n";
	}
};

class Camera
{
public:
	void takephoto()
	{
		cout << "相机可以照相～\n";
	}
	void show()
	{
		cout << "我是一台相机\n";
	}

};

class MobilePhone:public Phone,public Computer,public Camera
{
public:
	MobilePhone(const string& num):Phone(num){}
//	int calling;//子类中同名的标识符会隐藏父类中同名的标识符
//	int takephoto;
//	int coding;
};

int main()
{
	MobilePhone mp("110");
	mp.Phone::calling();
	mp.Computer::coding();
	mp.Camera::takephoto();
	mp.Phone::show();
	mp.Computer::show();//多个父类中有同名的标识符需要加类名来限定
	mp.Camera::show();
	Phone p = mp;
	p.calling();
	//p.coding();从子类对象转换为父类对象时，会把子类多余的方法和属性去掉
	//p.takephoto();
	Computer co = mp;
	co.coding();
	Camera ca = mp;
	ca.takephoto();
	return 0;	
}
