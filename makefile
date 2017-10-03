all: hw2

hw2: mainTerm.o number.o variable.o atom.o
ifeq (${OS}, Windows_NT)
	g++ -o hw2 mainTerm.o number.o variable.o atom.o -lgtest
else
	g++ -o hw2 mainTerm.o number.o variable.o atom.o -lgtest -lpthread
endif

mainTerm.o: mainTerm.cpp number.h utTerm.h
	g++ -std=gnu++11 -c mainTerm.cpp
number.o: number.cpp number.h
	g++ -std=gnu++11 -c number.cpp
variable.o:variable.cpp variable.h
	g++ -std=gnu++11 -c variable.cpp
atom.o:atom.cpp atom.h
	g++ -std=gnu++11 -c atom.cpp

clean:
	rm -f *.o hw2
stat:
	wc *.h *.cpp
