#include <iostream>

//命名空间嵌套
namespace n1{
	namespace n2{
		int num;
		
	}
	namespace n3{
		int num;
	}
	
}

int main()
{
	n1::n2::num = 100;
	n1::n3::num = 200;
	using namespace n1;
	n2::num = 100;
	using namespace n2;
	num = 200;
	using namespace n1::n3;
	num = 100;
}
