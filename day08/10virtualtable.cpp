#include<iostream>
using namespace std;
class A
{
private:
	int m_a;
	int m_b;
public:
	A(int a,int b):m_a(a),m_b(b){}
	virtual void func(){cout<<"void func()"<<endl;}
	virtual void bar(int d){cout<<"void bar(int d):"<<d<<endl;}
};
int main()
{
	cout<<sizeof(A)<<endl;
	A a(10,20);
	A b(20,40);
	int *pa=reinterpret_cast<int*>(&a);
	int *pb=reinterpret_cast<int*>(&b);
	cout<<pa<<endl;
	cout<<pb<<endl;
	cout<<*(pa+0)<<endl;
	cout<<*(pb+0)<<endl;
	cout<<*(pa+1)<<endl;//10
	cout<<*(pa+2)<<endl;//20
	/*int *arr=reinterpret_cast<int(*)>(*pa);
	void (*f)()=reinterpret_cast<void(*)()>(*arr);
	f();
	void (*fp)(A*,int)=reinterpret_cast<void (*)(A*,int)>(*(arr+1));
	fp(&b,100);*///重解释
	void (*f)()=(void (*)())
	(*(int*)(*(int*)&a));
	f();
	void (*pf)(A*,int)=(void (*)(A*,int))(*((int*)(*(int*)&a)+1));
	pf(&b,100);//强制转换
	return 0;
}
