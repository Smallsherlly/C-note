#include "managerview_console_imp1.h"
#include "managerservice_imp1.h"

int main()
{
	ManagerView* m = new ManagerviewConsoleImp1();
//	ManagerviewConsoleImp1 m;
	m->menu();
	delete m;
	return 0;	
}
