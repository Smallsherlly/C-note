#include <iostream>
#include <typeinfo>
using namespace std;

class A
{


};

class B:public A
{

};
int main()
{
	int a = 10;
	cout << typeid(a).name() << endl;
	char c = '0';
	cout << typeid(c).name() << endl;
	string s("hello");
	cout << typeid(s).name() << endl;
	A q;
	B w;
	cout << typeid(q).name() << endl;
	if(typeid(q).name() == typeid(w).name())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
