#ifndef ATOM_H
#define ATOM_H
#include "number.h"
#include "variable.h"
#include <string>

using namespace std;

class Number;
class Variable;
class Atom {
public:
  Atom (string s);
  string symbol();
  //bool operator ==(Atom a) {return _symbol == a._symbol;}
  bool match( Number num);
  bool match( Atom atom);
  bool match( Variable &x);
private:
  string _symbol;
};

#endif
