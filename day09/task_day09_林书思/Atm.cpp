#include <iostream>
#include <cstring>
#include <cstdlib>
#include <typeinfo>
using namespace std;

class Card
{
private:
	string m_num;
	double m_balance;
	char* m_name;
	string m_psw;
public:
	Card(){}
	Card(const Card& that)
	{
		m_num = that.m_num;
		m_balance = that.m_balance;
		m_name = new char[strlen(that.m_name?that.m_name:"")+1];
		m_psw = that.m_psw;
	}
	Card(string& num,double balance,char* name,string& psw)
	{
		m_num = num;
		m_balance = balance;
		m_name = new char[strlen(name?name:"")+1];
		m_psw = psw;
	}
	Card& operator=(const Card& that)
	{
		m_num = that.m_num;
		m_balance = that.m_balance;
		m_name = new char[strlen(that.m_name?that.m_name:"")+1];
		m_psw = that.m_psw;
	}
	const string& getId()
	{
		return m_num;
	}
	double getBalance()
	{
		return m_balance;
	}
	void setMoney(double money)
	{
		m_balance -= money;
	}
	void getMoney(double money)
	{
		m_balance += money;
	}
	void setPsw(const string& psw)
	{
		m_psw = psw;
	}
};

class Atm
{
private:
	Card* m_card;
	size_t m_account;
public:
	Atm(Card* card)
	{
		m_card = card;
	}
	Card* getCard()
	{
		return m_card;
	}
	virtual bool getMoney1(double money){}
	virtual bool getMoney2(double money){}
	virtual bool sendMoney1(double money,Card* cp){}
	virtual bool sendMoney2(double money,Card* cp){}
	virtual double checkMoney(){}
	virtual bool changePsw(const string& psw){}
	friend class ZG;
	friend class ZS;
	friend class JS;
};

class ZG:public Atm
{
public:
	ZG(Card* card):Atm(card){}
	virtual bool getMoney1(double money)
	{
		m_card->setMoney(money);
		return true;
	}
	virtual bool getMoney2(double money)
	{
		m_card->setMoney(money*1.1);
		return true;
	}
	virtual bool sendMoney1(double money,Card* cp)
	{
		m_card->setMoney(money);
		cp->getMoney(money);
		return true;
		
	}
	virtual bool sendMoney2(int money,Card* cp)
	{
		m_card->setMoney(money*1.1);
		cp->getMoney(money);
		return true;
	}
	virtual double checkMoney()
	{
		return m_card->getBalance();	
	}
	virtual bool changePsw(const string& psw)
	{
		m_card->setPsw(psw);
		return true;
	}
};

class ZS:public Atm
{
public:
	ZS(Card* card):Atm(card){}
	virtual bool getMoney1(double money)
	{
		m_card->setMoney(money);
		return true;
	}
	virtual bool getMoney2(double money)
	{
		m_card->setMoney(money+2);
		return true;
	}
	virtual bool sendMoney1(double money,Card* cp)
	{
		m_card->setMoney(money);
		cp->getMoney(money);
		return true;
		
	}
	virtual bool sendMoney2(int money,Card* cp)
	{
		m_card->setMoney(money+2);
		cp->getMoney(money);
		return true;
	}
	virtual double checkMoney()
	{
		return m_card->getBalance();	
	}
	virtual bool changePsw(const string& psw)
	{
		m_card->setPsw(psw);
		return true;
	}

};

class JS:public Atm
{
public:
	JS(Card* card):Atm(card){}
	virtual bool getMoney1(double money)
	{
		m_card->setMoney(money);
		return true;
	}
	virtual bool getMoney2(double money)
	{
		m_card->setMoney(money*1.1);
		return true;
	}
	virtual bool sendMoney1(double money,Card* cp)
	{
		m_card->setMoney(money);
		cp->getMoney(money);
		return true;
		
	}
	virtual bool sendMoney2(int money,Card* cp)
	{
		m_card->setMoney(money+2);
		cp->getMoney(money);
		return true;
	}
	virtual double checkMoney()
	{
		return m_card->getBalance();	
	}
	virtual bool changePsw(const string& psw)
	{
		m_card->setPsw(psw);
		return true;
	}
};
char s;
void anykey()
{
	cout << "输入任意指令返回.\n";
	cin >> s;
}
int main()
{
	int flag = 0;
	int i = 0,j = 0;
	int choice = 0;
	double money;
	string id;
	string psw;

	char name1[24] = "lss";
	char name2[24] = "stt";
	char name3[24] = "lily";
	string str1("111111");
	string str2("222222");
	string str3("333333");
	string psw1("3333");
	string psw2("4444");
	string psw3("5555");
	Card c1(str1,1000,name1,psw1);
	Card c2(str2,2000,name2,psw2);
	Card c3(str3,3000,name3,psw3);
	Atm* a[3];
	a[0] = new ZG(&c1);
	a[1] = new ZS(&c2);
	a[2] = new JS(&c3);
	/*
	if(typeid(JS).name() == typeid(*a[2]).name())
		cout << "YES\n";
	else
		cout << "NO\n";
		*/
	while(1)
	{
		cout << "请输入您的卡号：\n";
		cin >> id;
		for(i=0; i<3; i++)
		{
			if(!strcmp((a[i]->getCard()->getId()).c_str(),id.c_str()))
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			break;
		cout<< "该账户不存在！\n";
	}
	while(1)
	{
		system("clear");
		cout << "请选择您要进行的操作" << endl;
		cout << "1.取款" << endl;
		cout << "2.汇款" << endl;
		cout << "3.查看余额" << endl;
		cout << "4.修改交易密码" << endl;
		cout << "5.退出系统" << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "请选择您要进行的操作\n";
				cout << "1.同行取款\n";
				cout << "2.跨行取款\n";
				cin >> choice;
				cout << "请输入取款金额" << endl;
				cin >> money;
				if(choice == 1)
				{
					if(a[i]->getMoney1(money))
					{
						cout<< "取款成功～" << endl;
						anykey();
					}
				}else if(choice == 2)
				{
					if(a[i]->getMoney2(money))
					{
						cout<< "取款成功～" << endl;
						anykey();
					}
				}
				break;
			case 2:
				cout << "请选择您要进行的操作\n";
				cout << "1.同行汇款\n";
				cout << "2.跨行汇款\n";
				cin >> choice;
				cout << "请输入目标账户\n";
				cin >> id;
				cout << "请输入汇款金额" << endl;
				cin >> money;
				for(j=0; j<3; j++)
				{
					if(!strcmp((a[j]->getCard()->getId()).c_str(),id.c_str()))
					break;
				}
				if(j==3)
				{
					cout<< "该账户不存在！\n";
					anykey();
					break;
				}
				if(choice == 1)
				{
					if(a[i]->sendMoney1(money,a[j]->getCard()))
						cout<< "汇款成功～" << endl;
						anykey();
				}else if(choice == 2)
				{
					if(a[i]->sendMoney2(money,a[j]->getCard()))
						cout<< "汇款成功～" << endl;
						anykey();
				}
				break;
			case 3:
				cout << "余额：" << a[i]->checkMoney()<< endl;
				anykey();
				break;
			case 4:
				cout << "请输入新密码：\n";
				cin >> psw;
				if(a[i]->changePsw(psw))
				{
					cout << "修改密码成功～\n" ; 
					anykey();
				}
			case 5:
				return 0;
		}
	}	

}
