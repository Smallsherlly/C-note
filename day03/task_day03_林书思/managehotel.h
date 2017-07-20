#ifndef _MANAGEHOTEL_H__
#define _MANAGEHOTEL_H__
#include "hotel.h"
#include <cstdlib>
#include <cstdio>

namespace HM
{
	class ManageHotel
	{
		Hotel m_hotel;
	public:
		ManageHotel();
		ManageHotel(int row,int col);
		Hotel& get_hotel();
		void start();
	};
	
};


#endif// _MANAGEHOTEL_H__
