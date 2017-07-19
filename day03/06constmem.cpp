#include <iostream>
using namespace std;

class Phone
{
	const string m_brand;
	const string m_name;
public:
	Phone(const string& brand,const string& name):m_brand(brand),m_name(name)
	{

	}


};


int main()
{
	Phone p = Phone("小米","红米Note");

	
	return 0;	
}
