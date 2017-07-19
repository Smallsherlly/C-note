#ifndef _ROOM_H__
#define _ROOM_H__

#include "guest.h"
using namespace std;

namespace HM
{
	class Room
	{
		int m_id;
		bool m_isEmpty;
		Guest m_guest;
	public:
		Room(int id=0);
		bool in(const Guest& guest);
		bool out();
		bool getIsEmpty();
		Guest& getGuest();
		const int& getId();
		void setId(int id);
	};

};



#endif //_ROOM_H__
