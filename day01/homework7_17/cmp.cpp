#include <iostream>
#include <cstring>
using namespace std;

struct DATE
{
	short year;
	short month;
	short day;
	
	bool isLeap()
	{
		if(year%400 == 0&&year%100 == 0||year%4 == 0&&year%100 != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool isTrue()
	{
		if(year > 0&&year < 2018&&month > 0&&month < 13&&day > 0&&day < 32)
		{
			switch(month)
			{
				case 1:return 1;
				case 2:
				{
					if(isLeap())
					{
						if(day <30)
							return 1;
					}
					else
					{
						if(day < 29)
							return 1;
					}
					return 0;
				}
				case 3:return 1;
				case 4:
				{
					if(day < 31)
						return 1;
					return 0;
				}
				case 5:return 1;
				case 6:
				{
					if(day < 31)
						return 1;
					return 0;
				}
				case 7:return 1;
				case 8:return 1;
				case 9:
				{
					if(day < 31)
						return 1;
					return 0;
				}
				case 10:return 1;
				case 11:
				{
					if(day < 31)
						return 1;
					return 0;
				}
				case 12:return 1;
			}
		}
	}
	
	DATE nextday()
	{
		DATE date = {year,month,day};
		DATE error = {};
		int flag = isLeap();
		switch(month)
		{
			case 1:
			{
				if(day == 31)
				{
					date.month++;
					date.day = 1;
				}
				else
				{
					date.day++;
				}
				return date;
			}
			case 2:
			{
				if(flag == 1)
				{
					if(day == 29)
					{
						date.month++;
						date.day = 1;
					}
					else
					{
						date.day++;
					}
					return date;
				}
				else
				{
					if(day == 28)
					{
						date.month++;
						date.day = 1;
					}
					else
					{
						date.day++;
					}
					return date;
				}
				break;
			}
			case 3:
			{
				if(day == 31)
				{
					date.month++;
					date.day = 1;
				}
				else
				{
					date.day++;
				}
				return date;
			}
			case 4:
			{
				if(day < 31)
				{
					if(day == 30)
					{
						date.month++;
						date.day = 1;
					}
					else
					{
						date.day++;
					}
						return date;
				}
				break;
			}
			case 5:
			{
				if(day == 31)
				{
					date.month++;
					date.day = 1;
				}
				else
				{
					date.day++;
				}
				return date;
			}
			case 6:
			{
				if(day < 31)
				{
					if(day == 30)
					{
						date.month++;
						date.day = 1;
					}
					else
					{
						date.day++;
					}
						return date;
				}
				break;
			}
			case 7:
			{
				if(day == 31)
				{
					date.month++;
					date.day = 1;
				}
				else
				{
					date.day++;
				}
				return date;
			}
			case 8:
			{
				if(day == 31)
				{
					date.month++;
					date.day = 1;
				}
				else
				{
					date.day++;
				}
				return date;
			}
			case 9:
			{
				if(day < 31)
				{
					if(day == 30)
					{
						date.month++;
						date.day = 1;
					}
					else
					{
						date.day++;
					}
						return date;
				}
				break;
			}
			case 10:
			{
				if(day == 31)
				{
					date.month++;
					date.day = 1;
				}
				else
				{
					date.day++;
				}
				return date;
			}
			case 11:
			{
				if(day < 31)
				{
					if(day == 30)
					{
						date.month++;
						date.day = 1;
					}
					else
					{
						date.day++;
					}
						return date;
				}
				break;
			}
			case 12:
			{
				if(day == 31)
				{
					date.year++;
					date.month = 1;
					date.day = 1;
				}
				else
				{
					date.day++;
				}
				return date;
			}
		}
			
	}
	
	DATE nextday(int n)
	{
		DATE date = {year,month,day};
		DATE error = {};
		int flag = isLeap();
		
		switch(month)
		{
			case 1:
			{
				if(n >= 0)
				{
					if(day+n >= 31)
					{
						date.month++;
						date.day = day+n-31;
					}
					else
					{
						date.day = day+n;
					}
				}
				else
				{
					if(day+n <= 0)
					{
						date.month--;
						date.day = day+31+n;
					}
					else
					{
						date.day = day+n;
					}
				}
				return date;
			}
			case 2:
			{
				if(flag == 1)
				{
					if(n >= 0)
					{
						if(day+n >= 29)
						{
							date.month--;
							date.day = day+29+n;
						}
						else
						{
							date.day = day+n;
						}
					}
					else
					{
						if(day+n <= 0)
						{
							date.month--;
							date.day = day+n+31;
						}
						else
						{
							date.day = day+n;
						}
					}
					return date;
				}
				else
				{
					if(n >= 0)
					{
						if(day+n >= 28)
						{
							date.month++;
							date.day = day+n-28;
						}
						else
						{
							date.day = day+n;
						}
					}
					else
					{
						if(day+n <= 0)
						{
							date.month--;
							date.day = day+n+31;
						}
						else
						{
							date.day = day+n;
						}
					}
					return date;
				}
				break;
			}
			case 3:
			{
				if(n >= 0)
				{
					if(day+n >= 31)
					{
						date.month++;
						date.day = day+n-31;
					}
					else
					{
						date.day = day+n;
					}
				}
				else
				{
					if(day+n <= 0)
					{
						date.month--;
						if(flag == 1)
							date.day = day+29+n;
						else
							date.day = day+28+n;
					}
					else
					{
						date.day = day+n;
					}
				}
				return date;
			}
			case 4:
			{
				if(day < 31)
				{
					if(n >= 0)
					{
						if(day+n >= 30)
						{
							date.month++;
							date.day = day+n-30;
						}
						else
						{
							date.day = day+n;
						}
					}
					else
					{
						if(day+n <= 0)
						{
							date.month--;
							date.day = day+n+31;
						}
						else
						{
							date.day = day+n;
						}
					}
						return date;
				}
				break;
			}
			case 5:
			{
				if(n >= 0)
				{
					if(day+n >= 31)
					{
						date.month++;
						date.day = day+n-31;
					}
					else
					{
						date.day = day+n;
					}
				}
				else
				{
					if(day+n <= 0)
					{
						date.month--;
						date.day = day+30+n;
					}
					else
					{
						date.day = day+n;
					}
				}
				return date;
			}
			case 6:
			{
				if(day < 31)
				{
					if(n >= 0)
					{
						if(day+n >= 30)
						{
							date.month++;
							date.day = day+n-30;
						}
						else
						{
							date.day = day+n;
						}
					}
					else
					{
						if(day+n <= 0)
						{
							date.month--;
							date.day = day+n+31;
						}
						else
						{
							date.day = day+n;
						}
					}
						return date;
				}
				break;
			}
			case 7:
			{
				if(n >= 0)
				{
					if(day+n >= 31)
					{
						date.month++;
						date.day = day+n-31;
					}
					else
					{
						date.day = day+n;
					}
				}
				else
				{
					if(day+n <= 0)
					{
						date.month--;
						date.day = day+30+n;
					}
					else
					{
						date.day = day+n;
					}
				}
				return date;
			}
			case 8:
			{
				if(n >= 0)
				{
					if(day+n >= 31)
					{
						date.month++;
						date.day = day+n-31;
					}
					else
					{
						date.day = day+n;
					}
				}
				else
				{
					if(day+n <= 0)
					{
						date.month--;
						date.day = day+31+n;
					}
					else
					{
						date.day = day+n;
					}
				}
				return date;
			}
			case 9:
			{
				if(day < 31)
				{
					if(n >= 0)
					{
						if(day+n >= 30)
						{
							date.month++;
							date.day = day+n-30;
						}
						else
						{
							date.day = day+n;
						}
					}
					else
					{
						if(day+n <= 0)
						{
							date.month--;
							date.day = day+n+31;
						}
						else
						{
							date.day = day+n;
						}
					}
						return date;
				}
				break;
			}
			case 10:
			{
				if(n >= 0)
				{
					if(day+n >= 31)
					{
						date.month++;
						date.day = day+n-31;
					}
					else
					{
						date.day = day+n;
					}
				}
				else
				{
					if(day+n <= 0)
					{
						date.month--;
						date.day = day+30+n;
					}
					else
					{
						date.day = day+n;
					}
				}
				return date;
			}
			case 11:
			{
				if(day < 31)
				{
					if(n >= 0)
					{
						if(day+n >= 30)
						{
							date.month++;
							date.day = day+n-30;
						}
						else
						{
							date.day = day+n;
						}
					}
					else
					{
						if(day+n <= 0)
						{
							date.month--;
							date.day = day+n+31;
						}
						else
						{
							date.day = day+n;
						}
					}
						return date;
				}
				break;
			}
			case 12:
			{
				if(n >= 0)
				{
					if(day+n >= 31)
					{
						date.month++;
						date.day = day+n-31;
					}
					else
					{
						date.day = day+n;
					}
				}
				else
				{
					if(day+n <= 0)
					{
						date.month--;
						date.day = day+30+n;
					}
					else
					{
						date.day = day+n;
					}
				}
				return date;
			}
		}
			
	}

};

bool cmp(char a,char b)
{
	return a>b?true:false;
}

bool cmp(int a,int b)
{
	return a>b?true:false;
}

bool cmp(char* a,char* b)
{
	return strcmp(a,b)>=0?true:false;
}

bool cmp(int* a,int* b)
{
	return *a>*b?true:false;
}


bool cmp(DATE a,DATE b)
{
	if(a.year > b.year)
	{
		return 1;
	}
	else if(a.year < b.year)
	{
		return 0;
	}
	else
	{
		if(a.month > b.month)
		{
			return 1;
		}
		else if(a.month < b.month)
		{
			return 0;
		}
		else
		{
			if(a.month > b.month)
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		
		}
	}
}

typedef bool (*cmpp1)(char,char);
typedef bool (*cmpp2)(int,int);
typedef bool (*cmpp3)(char*,char*);
typedef bool (*cmpp4)(int*,int*);
typedef bool (*cmpp5)(DATE,DATE);

int main()
{
	cmpp1 pmc1 = cmp;
	cmpp2 pmc2 = cmp;
	cmpp3 pmc3 = cmp;
	cmpp4 pmc4 = cmp;
	cmpp5 pmc5 = cmp;
	
	char a1 = 'c';
	char b1 = 'b';
	int a2 = 3;
	int b2 = 5;
	char* a3 = &a1;
	char* b3 = &b1;
	int* a4 = &a2;
	int* b4 = &b2;
	DATE a5 = {2017,5,5};
	DATE b5 = {2016,6,6};
	cout << pmc1(a1,b1) << endl;
	cout << pmc2(a2,b2) << endl;
	cout << pmc3(a3,b3) << endl;
	cout << pmc4(a4,b4) << endl;
	cout << pmc5(a5,b5) << endl;
	return 0;	
}
