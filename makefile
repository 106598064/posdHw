all: hw8 shell

hw8: expression.o atom.o struct.o list.o

ifeq (${OS}, Windows_NT)
	g++ -o hw8 expression.o atom.o list.o struct.o -lgtest
else
	g++ -o hw8 expression.o atom.o list.o struct.o -lgtest -lpthread
endif

shell: Shell.o atom.o struct.o list.o

ifeq (${OS}, Windows_NT)
	g++ -o shell Shell.o atom.o list.o struct.o -lgtest
else
	g++ -o shell Shell.o atom.o list.o struct.o -lgtest -lpthread
endif

atom.o: atom.cpp atom.h variable.h
	g++ -std=gnu++0x -c atom.cpp
list.o:list.cpp list.h
		g++ -std=gnu++0x -c list.cpp
struct.o:struct.cpp struct.h
		g++ -std=gnu++0x -c struct.cpp


expression.o: expression.cpp expression.h exception.h
	g++ -std=gnu++0x -c expression.cpp

Shell.o: Shell.cpp
	g++ -std=gnu++0x -c Shell.cpp


clean:
	rm -f *.o hw8

stat:
	wc *.h *.cpp
