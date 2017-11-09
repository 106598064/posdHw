#ifndef ATOM_H
#define ATOM_H
#include "term.h"
#include <string>
#include <sstream>
#include <vector>
using namespace std;




class Atom : public Term{
public:
  Atom(string s):Term(s) {}
};

/*class Number : public Term{
public:
  Number(double db):Term(db) {}
};*/

#endif
