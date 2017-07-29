CC=g++
OBJ=main.o manager.o managerview_console_imp1.o managerservice_imp1.o managerdao_file_imp1.o serviceview_console_imp1.o service_imp1.o tools.o department.o employee.o servicedao_file_imp1.o
BIN=EMIS

$(BIN):$(OBJ)
	$(CC) -g $(OBJ) -o $(BIN)

main.o:main.cpp
managerview_console_imp1.o:managerview_console_imp1.cpp managerview_console_imp1.h managerview.h tools.h

managerservice_imp1.o:managerservice_imp1.cpp managerservice_imp1.h managerservice.h

manager.o:manager.cpp manager.h

managerdao_file_imp1.o:managerdao_file_imp1.cpp managerdao_file_imp1.h managerdao.h 

serviceview_console_imp1.o:serviceview_console_imp1.cpp serviceview_console_imp1.h serviceview.h tools.h

service_imp1.o:service_imp1.cpp service_imp1.h service.h

servicedao_file_imp1.o:servicedao_file_imp1.cpp servicedao_file_imp1.h servicedao.h
tools.o:tools.cpp tools.h

department.o:department.cpp department.h

employee.o:employee.cpp employee.h
clean:
	-rm $(OBJ) $(BIN) *.cpp~ *.h~  *.h.gch
