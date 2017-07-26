#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
	char buf[] = "123 456 hello";
	istringstream is(buf);
	int d1 = 0;
	int d2 = 0;
	string s;
	if(is)
		is>>d1>>d2>>s;
	cout << d1 << ":" << d2 << ":" << s << endl;
	return 0;	
}
