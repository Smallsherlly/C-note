#include "managerview_console_imp1.h"
#include "tools.h"
#include <fstream>
ManagerviewConsoleImp1::ManagerviewConsoleImp1()
{
	m_service = new ManagerServiceImp1();
	m_serviceview = new ServiceViewConsoleImp1();
}
void ManagerviewConsoleImp1::menu()
{
	int id;
	char psw[20] = {};
	int choice;
	while(1)
	{
		system("clear");
		show();

		cin >> choice;

		switch(choice)
		{
			case 1:
				add();
				break;
			case 2:
				del();
				break;
			case 3:
				list();
				break;
			case 4:
				cout << "请输入管理员ID\n";
				cin >> id;
				cout << "请输入管理员密码\n";
				cin >> psw;
				if(m_service->login(id,psw))
				{
					m_serviceview->menu();
					break;
				}
				else
					cout << "账户或密码有误\n";
				cin.get();
				anykey();
				break;
			case 0:
				return;
		}
	}
}

void ManagerviewConsoleImp1::add()
{
	string name;
	string psw;
	
	
	int id = generator_id();

	cout << "请输入管理员用户名：\n";
	cin >> name;
	cout << "请输入管理员密码：\n";
	cin >> psw;
	m_service->addManager(id,name.c_str(),psw.c_str());
	
	
	cin.get();
	anykey();
}
void ManagerviewConsoleImp1::show()
{
	cout << "企业管理信息系统\n";
	cout << "----------------\n";
	cout << "[1]增加管理员\n";
	cout << "[2]删除管理员\n";
	cout << "[3]列出所有管理员\n";
	cout << "[4]运营管理\n";
	cout << "[0]退出\n";
	cout << "---------------\n";
	cout << "请选择：\n";
}
void ManagerviewConsoleImp1::del()
{
	int id = 0;
	cout << "请输入管理员ID：\n";
	cin >> id;
	m_service->deleteManager(id);
}

void ManagerviewConsoleImp1::list()
{
	vector<Manager> m_managers = m_service->listManager();
	vector<Manager>::iterator vs = m_managers.begin();
	cout<< "管理员ID   管理员姓名   管理员密码\n";
	cout<< "------------------------------------\n";
	for(; vs!=m_managers.end(); vs++)
	{
		cout << *vs << endl;
	}
	cin.get();
	anykey();
}

ManagerviewConsoleImp1::~ManagerviewConsoleImp1()
{
	if(m_service != NULL)
		delete m_service;
	m_service = NULL;
	if(m_serviceview != NULL)
		delete m_serviceview;
	m_serviceview = NULL;
}
