#include <iostream>

using namespace std;

namespace date
{
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

	bool isLeap(short year,short month,short day=1);
	bool isLeap(short year,short month,short day)
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
 	bool isLeap(DATE d)
 	{
 		if(d.year%400 == 0&&d.year%100 == 0||d.year%4 == 0&&d.year%100 != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
 	}

}
int main()
{
	using namespace date;
	DATE date = {};
	int n = 0;
	cout << "请输入日期（用空格隔开）" << endl;
	cin >> date.year >> date.month >> date.day;
	cout << "请输入偏移量n" << endl;
	cin >> n;
	DATE new1 = date.nextday(n);
	cout << "year:" << new1.year << " month:" << new1.month << " day: " << new1.day << endl;
	return 0;	
}
