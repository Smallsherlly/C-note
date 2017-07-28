CC=g++
OBJ=main.o manager.o managerview_console_imp1.o managerservice_imp1.o managerdao_file_imp1.o
BIN=EMIS

$(BIN):$(OBJ)
	$(CC) -g $(OBJ) -o $(BIN)

main.o:main.cpp
managerview_console_imp1.o:managerview_console_imp1.cpp managerview_console_imp1.h managerview.h

managerservice_imp1.o:managerservice_imp1.cpp managerservice_imp1.h managerservice.h

manager.o:manager.cpp manager.h

managerdao_file_imp1.o:managerdao_file_imp1.cpp managerdao_file_imp1.h managerdao.h 
clean:
	-rm $(OBJ) $(BIN) *.cpp~ *.h~  *.h.gch
