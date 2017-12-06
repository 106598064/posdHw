all: hw7

hw7: mainIterator.o atom.o term.o struct.o list.o
ifeq (${OS}, Windows_NT)
	g++ -o hw7 mainIterator.o atom.o term.o struct.o list.o -lgtest
else
	g++ -o hw7 mainIterator.o atom.o term.o struct.o list.o -lgtest -lpthread
endif

mainIterator.o: mainIterator.cpp utIterator.h
	g++ -std=gnu++11 -c mainIterator.cpp
atom.o: atom.cpp atom.h
	g++ -std=gnu++11 -c atom.cpp
term.o: term.cpp term.h
	g++ -std=gnu++11 -c term.cpp
struct.o:struct.cpp struct.h
	g++ -std=gnu++11 -c struct.cpp
list.o:list.cpp list.h
	g++ -std=gnu++11 -c list.cpp

clean:
	rm -f *.o hw7
stat:
	wc *.h *.cpp
