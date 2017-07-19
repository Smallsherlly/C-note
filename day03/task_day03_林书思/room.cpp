#include "room.h"

using namespace HM;

Room::Room(int id):m_id(id)
{
	m_isEmpty = true;
}

bool Room::in(const Guest& guest)
{
	if(m_isEmpty)
	{
		m_isEmpty = false;
		m_guest = guest;//赋值
	}
	return true;
}

bool Room::out()
{
	if(!m_isEmpty)
	{	
		m_isEmpty = true;
		m_guest.setName("nvl");
	}
	return true;
}


bool Room::getIsEmpty()
{
	return m_isEmpty;
}

Guest& Room::getGuest()
{
	return m_guest;
}

const int& Room::getId()
{
	return m_id;
}

void Room::setId(int id)
{
	m_id = id;
}

