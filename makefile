all: hw4 utAtom utVariable

hw4:	mainList.o term.o atom.o
	g++	-o	hw4 mainList.o term.o atom.o -lgtest -lpthread
utAtom: mainAtom.o atom.o term.o
	g++	-o	utAtom mainAtom.o	term.o atom.o -lgtest -lpthread
utVariable: mainVariable.o atom.o term.o
	g++	-o	utVariable mainVariable.o	term.o atom.o -lgtest -lpthread

mainVariable.o: mainVariable.cpp utVariable.h variable.h term.h
	g++ -std=c++11 -c mainVariable.cpp
mainAtom.o: mainAtom.cpp utAtom.h
	g++ -std=c++11 -c mainAtom.cpp
mainList.o: mainList.cpp utList.h
	g++ -std=c++11 -c mainList.cpp
term.o: term.cpp term.h variable.h
	g++ -std=c++11 -c term.cpp
atom.o: atom.cpp atom.h term.h number.h
	g++ -std=c++11 -c atom.cpp


clean:
	rm -f *.o *hw4
stat:
	wc *.h *.cpp
