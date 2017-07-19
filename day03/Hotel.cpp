#include <iostream>
#include <cstring>

using namespace std;

class Guest
{
public:
	char* m_name;
	Guest(char name[24] = "nvl"):m_name(name){}
};

class Room
{
public:
	int m_id;
	bool m_isEmpty;
	Guest m_guest;
	Room()
	{

	}
};

class Hotel
{
public:
	int m_row;
	int m_col;
	Room (*m_room)[6];
	Hotel(int row = 5,int col = 6):m_row(row),m_col(col),m_room(new Room[5][6])
	{
		int i = 0;
		int j = 0;
		for(i=0; i<m_row; i++)
		{
			for(j=0; j<m_col; j++)
			{
				m_room[i][j].m_id = i*100+j;
			}
		}
	}
};

class ManageHotel
{
public:
	Hotel m_hotel;
	void check()
	{
		int i = 0;
		int j = 0;
		for(j=0; j<m_hotel.m_row; j++)
		{
			for(i=0; i<m_hotel.m_col; i++)
			{
				if(j == 0)
				{
					cout << "00" << m_hotel.m_room[j][i].m_id << "  ";
				}
				else
				{
					cout << m_hotel.m_room[j][i].m_id << "  ";
				}
			}
			cout << "\n";
			for(i=0; i<m_hotel.m_col; i++)
			{
				cout << m_hotel.m_room[j][i].m_guest.m_name << "  ";
			}
			cout << "\n\n";
		}
	}

	void check_in(int id,char* name)
	{
		int i = 0;
		int j = 0;
		for(i=0; i<m_hotel.m_row; i++)
		{
			for(j=0; j>m_hotel.m_col; j++)
			{
				if(m_hotel.m_room[i][j].m_id == id)
				{
					strcpy(m_hotel.m_room[i][j].m_guest.m_name,name);
				}
			}
		}
	}

	void check_out(int id,char* name)
	{

	}


};


int main()
{
	int in;
	char name[24];
	int id;
	ManageHotel man;
	while(1)
	{
		cin >> in;
		switch(in)
		{
			case 1:
			{
				man.check();
				break;
			}
			case 2:
			{
				cout << "请输入入住房间号" << endl;
				cin >> id;
				cout << "请输入住人姓名" << endl;
				cin >> name;
				man.check_in(id,name);
				break;
			}
			case 3:
			{
				cout << "请输入退房房间号" << endl;
				cin >> id;
				cout << "请输入退房人姓名" << endl;
				cin >> name;
				man.check_out(id,name);
				break;
			}
			case 4:
			{
				return 0;
			}
		}
	}
	
	
	return 0;
}
