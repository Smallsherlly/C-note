CC=g++
OBJ=guest.o room.o hotel.o managehotel.o main.o
SRC=guest.cpp room.cpp hotel.cpp managehotel.cpp main.cpp
BIN=ManagerHotel

all:obj
	$(CC)  $(OBJ) -o $(BIN)
obj:
	$(CC) -c $(SRC)
clean:
	rm $(OBJ) $(BIN) *.h.gch
