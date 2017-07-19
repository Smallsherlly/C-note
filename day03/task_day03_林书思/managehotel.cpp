#include "managehotel.h"
using namespace HM;

	
const Hotel& ManageHotel::get_hotel()
{
	return m_hotel;
}

void ManageHotel::start()
{
	ManageHotel manage;
	Guest guest;
	int in_num;
	string name;
	int op = 0;
	int i = 0;
	int j = 0;
	while(1)
	{
		system("clear");
		cout << "酒店管理系统" <<endl;
		cout << "1.查看酒店入住情况" <<endl;
		cout << "2.办理入住" <<endl;
		cout << "3.办理退房" <<endl;
		cout << "4.退出系统" <<endl;
		cout << "请输入指令\n";
		cin >> op;
		switch(op)
		{
			case 1:
			{
				Hotel man = manage.get_hotel();
				man.search();
				getchar();
				break;
			}
			case 2:
			{
			
				cout << "请输入入住房间" << endl;
				cin >> in_num;
				cout << "请输入入住人姓名" << endl;
				cin >> name;
				guest.setName(name);
				i = in_num/100;
				j = in_num%100;
				i = i*6+j;
				Hotel man = manage.get_hotel();
				if(man.getRoom()[i].getIsEmpty())
				{
					man.in(in_num,name);
					man.getRoom()[i].in(guest);
					cout << "入住成功！\n";
					
				}
				else
				{
					cout << "对不起，您所选的房间已有人入住。" << endl;
				}
				getchar();
				break;
			}
			case 3:
			{
			
				cout << "请输入退房房间" << endl;
				cin >> in_num;
				i = in_num/100;
				j = in_num%100;
				i = i*6+j;
				Hotel man = manage.get_hotel();
				man.getRoom()[i].out();
				cout << "退房成功！\n";
				getchar();
				break;
			}
			case 4:
			{
				return;
			}

		}
		scanf("%*c");
	}


}

