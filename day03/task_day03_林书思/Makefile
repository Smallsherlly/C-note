
OBJ=guest.o room.o hotel.o managehotel.o main.o

ManageHotel:$(OBJ)
	$(CXX) $(OBJ) -o ManageHotel
main.o:main.cpp  
hotel.o:hotel.cpp hotel.h
guest.o:guest.cpp guest.h
room.o:room.cpp guest.h
managehotel.o:managehotel.cpp managehotel.h

clean:
	-rm $(OBJ)
