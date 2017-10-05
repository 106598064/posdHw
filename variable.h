#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "atom.h"
#include "number.h"
using std::string;

class Atom;
class Number;
class Variable{
public:
  Variable(string s);
  string const _symbol;
  string value(); //值
  /*bool match( Atom atom ){
    bool ret = _assignable;
    if(_assignable){
      _value = atom._symbol ;
      _assignable = false;
    }
    return ret;
  }*/
  bool match( string s);
  bool match( Number& num);
  bool match( Atom& atom);
  bool checkassign();
  void notassign();
private:
  string _value;
  bool _assignable = true;
};

#endif
