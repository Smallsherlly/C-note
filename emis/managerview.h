#ifndef _MANAGERVIEW_H__
#define _MANAGERVIEW_H__

class ManagerView
{
public:
	virtual ~ManagerView(){};
	virtual void menu()=0;
	virtual void add()=0;
	virtual void del()=0;
	virtual void list()=0;
};


#endif //_MANAGERVIEW_H__
