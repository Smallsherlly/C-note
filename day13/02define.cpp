#include <iostream>
using namespace std;

#define MAX(T) T max##T(T x,T y){\
	return x>y?x:y;\
}
// “##”拼接
MAX(int)
MAX(double)
MAX(string)
//生成三个函数
#define max(T) max##T
//调用时替换成以上的三个函数之一
int main()
{
	cout << max(int)(1,10) << endl;
	cout << max(double)(3.14,5.68) << endl;
	cout << max(string)("hello","world") << endl;
	return 0;
}
