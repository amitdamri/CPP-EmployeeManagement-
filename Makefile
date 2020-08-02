run:main.o DataBase.o Employee.o
	g++ DataBase.o Employee.o main.o -o run
DataBase.o:DataBase.cpp DataBase.h Employee.h
	g++ -c DataBase.cpp
Employee.o:Employee.cpp Employee.h
	g++ -c Employee.cpp
main.o:main.cpp DataBase.h Employee.h
	g++ -c main.cpp
clean:
	rm -f *.o rm -f run 
