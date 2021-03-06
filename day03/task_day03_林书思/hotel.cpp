#include "hotel.h"
using namespace HM;

Hotel::Hotel(){};
Hotel::Hotel(int layer,int count):m_layer(layer),m_count(count)
{
	int i = 0;
	int j = 0;
	m_room = new Room[layer*count];
	for(i=0; i<layer; i++)
	{
		for(j=0; j<count; j++)
		{
			m_room[i*count+j].setId(i*100+j);
		}
	}
}
Hotel::Hotel(const Hotel& hotel):m_layer(hotel.m_layer),m_count(hotel.m_count)
{
	int i = 0;
	int j = 0;
	m_room = new Room[m_layer*m_count];
	for(i=0; i<m_layer; i++)
	{
		for(j=0; j<m_count; j++)
		{
			m_room[i*m_count+j].setId(i*100+j);
		}
	}
}
Hotel::~Hotel()
{
	if(m_room!=NULL)
		delete[] m_room;
	m_room = NULL;
}

Room* Hotel::getRoom()
{
	return m_room;
}

bool Hotel::in(int id,Guest guest)
{
	int i = 0;
	int j = 0;
	for(i=0; i<m_layer; i++)
	{
		for(j=0; j<m_count; j++)
		{
			if(m_room[i*j].getId() == id)
			{
				if(m_room[i*j].getIsEmpty())
					return true;
				return 0;
			}
		}
	}
	return 0;
}

bool Hotel::out(int id)
{
	int i = 0;
	int j = 0;
	for(i=0; i<m_layer; i++)
	{
		for(j=0; j<m_count; j++)
		{
			if(m_room[i*j].getId() == id)
			{
				m_room[i*j].getGuest().setName("nvl");
				return true;
			}
			return false;
		}
	}
	return false;
}

void Hotel::search()
{
	int i = 0;
	int j = 0;
	for(i=0; i<m_layer; i++)
	{
		for(j=0; j<m_count; j++)
		{
			if(i == 0)
			{
				cout << "00" << m_room[i*m_count+j].getId() << "  ";
			}
			else
				cout << m_room[i*m_count+j].getId() << "  ";
		}
		cout << endl;
		for(j=0; j<m_count; j++)
		{
			cout << m_room[i*m_count+j].getGuest().getName() << "  ";
		}
		cout << "\n\n";
	}

}
