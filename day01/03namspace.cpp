#include <iostream>
using namespace std;

//声明一个命名空间n1
namespace n1{
	int num;
	void show()
	{
		cout << "show()" << endl;
	}
	void func();//只有声明，没有定义
}

namespace n1{
	double dnum;
	void print();
}

void n1::print(){
	cout << "print()" << endl;
}
//在命名空间以外的地方实现函数功能
void n1::func()
{
	cout << "func()" << endl;
}
using namespace n1;//1  using namespace std  把std中所有的内容导入到程序中
int main()
{
	n1::num = 100;//2  n1::   直接从命名空间中调用某个变量或者函数
	cout << n1::num << endl;	
	using n1::show;//3.导入命名空间里的某个变量或者函数
	show();//可以直接访问
	func();
	return 0;	
}
