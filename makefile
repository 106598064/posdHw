all: hw6

hw6: mainParser.o atom.o term.o
ifeq (${OS}, Windows_NT)
	g++ -o hw6 mainParser.o atom.o term.o -lgtest
else
	g++ -o hw6 mainParser.o atom.o term.o -lgtest -lpthread
endif

mainParser.o: mainParser.cpp utParser.h
	g++ -std=gnu++11 -c mainParser.cpp
atom.o: atom.cpp atom.h
	g++ -std=gnu++11 -c atom.cpp
term.o: term.cpp term.h
	g++ -std=gnu++11 -c term.cpp

clean:
	rm -f *.o hw6
stat:
	wc *.h *.cpp
