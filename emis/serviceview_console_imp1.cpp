#include "serviceview_console_imp1.h"
#include "tools.h"
#include <cstdlib>
#include <cstring>
ServiceViewConsoleImp1::ServiceViewConsoleImp1()
{
	m_pService = new ServiceImp1();	
}

ServiceViewConsoleImp1::~ServiceViewConsoleImp1()
{
	if(NULL != m_pService)
		delete m_pService;
	m_pService = NULL;	
}

void ServiceViewConsoleImp1::menu()
{
	int choice = 0;
	
	while(1)
	{
		system("clear");
		show();
		cin >> choice;
		switch(choice)
		{
			case 1:
				addDept();
				break;
			case 2:
				deleteDept();
				break;
			case 3:
				listDept();
				break;
			case 4:
				addEmp();
				break;
			case 5:
				deleteEmp();
				break;
			case 6:
				modifyEmp();
				break;
			case 7:
				listEmp();
				break;
			case 8:
				listAllEmp();
				break;
			case 0:
				return;
		}
	}
}

void ServiceViewConsoleImp1::show()
{
	cout << "运营管理子系统\n";
	cout << "----------------\n";
	cout << "[1]增加部门\n";
	cout << "[2]删除部门\n";
	cout << "[3]列出部门\n";
	cout << "[4]增加员工\n";
	cout << "[5]删除员工\n";
	cout << "[6]修改员工信息\n";
	cout << "[7]列出部门员工\n";
	cout << "[8]列出所有员工\n";
	cout << "[0]返回\n";
	cout << "---------------\n";
	cout << "请选择:\n";
}

bool ServiceViewConsoleImp1::addDept()
{
	string name;
	cout << "请输入部门名称\n";
	cin >> name;
	if(m_pService->addDept(name))
	cout << "增加部门成功！\n";
	cin.get();
	anykey();
}

bool ServiceViewConsoleImp1::deleteDept()
{
	int id = 0;
	cout << "请输入部门ID\n";
	cin >> id;
	if(m_pService->deleteDept(id))
	cout << "删除部门成功！\n";
	cin.get();
	anykey();

}

void ServiceViewConsoleImp1::listDept()
{
	vector<Department> de = m_pService->listDept();
	vector<Department>::iterator it =  de.begin();
	cout << "部门ID   部门名称   部门人数    \n";
	cout << "------------------------------\n";
	for(;it!=de.end();it++)
		cout << *it << endl;
	cin.get();
	anykey();
}

bool ServiceViewConsoleImp1::addEmp()
{
	string name;
	bool sex;
	int age;
	int id;
	cout << "请输入员工姓名:\n";
	cin >> name;
	cout << "请输入员工性别:\n";
	cin >> sex;
	cout << "请输入员工年龄:\n";
	cin >> age;
	cout << "请输入部门ID\n";
	cin >> id;
	if(m_pService->addEmp(id,name,sex,age))
	cout << "增加员工成功！\n";
	cin.get();
	anykey();

}

bool ServiceViewConsoleImp1::deleteEmp()
{
	int id = 0;
	cout << "请输入员工ID\n";
	cin >> id;
	if(m_pService->deleteEmp(id))
	cout << "删除员工成功！\n";

	cin.get();
	anykey();

}

bool ServiceViewConsoleImp1::modifyEmp()
{
	string name;
	bool sex;
	int age;
	int id;
	cout << "请输入员工ID\n";
	cin >> id;
	cout << "请输入员工姓名:\n";
	cin >> name;
	cout << "请输入员工性别:\n";
	cin >> sex;
	cout << "请输入员工年龄:\n";
	cin >> age;
	
	if(m_pService->modifyEmp(id,name,sex,age))
		cout << "修改员工信息成功！\n";
	else
		cout << "该ID不存在\n";
		
	cin.get();
	anykey();
}

void ServiceViewConsoleImp1::listEmp()
{
	int id;
	cout << "请输入部门ID：";
	cin >> id;
	vector<Employee> emp = m_pService->listEmp(id);
	if(emp.size()==0)
		cout << "该部门不存在或者没有员工\n";
	vector<Employee>::iterator it = emp.begin();
	cout << "员工ID     姓名    性别    年龄\n";
	cout << "------------------------------\n";
	for(;it!=emp.end();it++)
		cout << *it << endl;
		
	cin.get();
	anykey();
}

void ServiceViewConsoleImp1::listAllEmp()
{
	vector<Department> de = m_pService->listAllEmp();
	vector<Department>::iterator it = de.begin();
	cout << "员工ID     姓名    性别    年龄\n";
	cout << "------------------------------\n";
	for(;it != de.end();it++)
	{
		vector<Employee> emp = (*it).getEmployee();
		vector<Employee>::iterator pt = emp.begin();
		for(;pt!=emp.end();pt++)
			cout << *pt << endl;
	}
	cin.get();
	anykey();
}




