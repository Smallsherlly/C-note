#include <iostream>

using namespace std;

enum S{SPR,SUM,ACT,WIN};


int main()
{
	S s = ACT;
	cout << s <<endl;
	//s = 0; 不可以直接把int类型直接赋值给枚举类型	
	return 0;	
}
