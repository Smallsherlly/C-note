#include <iostream>
using namespace std;

class Iphone
{
private:
	static string m_compay;
	string m_version;
public:
	Iphone(string version):m_version(version)
	{

	}
	static void show(){
		//静态函数里没有this指针
		cout << "静态函数" << endl;
		cout << m_compay << endl;
	}
};
//属性成员必须在类外初始化
string Iphone::m_compay = "Apple";

int main()
{
	Iphone ip5("Iphone 7p");
	Iphone::show();
	ip5.show();

	return 0;	
}
