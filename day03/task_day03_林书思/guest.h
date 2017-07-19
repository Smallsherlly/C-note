#ifndef _GUEST_H__
#define _GUEST_H__

#include <iostream>
using namespace std;


namespace HM
{
	class Guest
	{
		string m_name;

	public:
		Guest(const string& name="nvl");
		string& getName();
		void setName(const string& name);
	};
};




#endif //GUEST_H__
