#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "atom.h"
#include "number.h"
using namespace std;

class Number;

class Variable:public Term{
public:
  Variable(string s):_symbol(s),_value(s){}
  string const _symbol;
  string symbol() const;
  string value() const;
  /*bool match( Atom atom ){
    bool ret = _assignable;
    if(_assignable){
      _value = atom._symbol ;
      _assignable = false;
    }
    return ret;
  }*/
  bool match(Atom& atom);
  bool match(Number& num);
  bool match(Variable& x);
  //bool match(Term &term);
  bool checkassign();
  void notassign();
  void change(string s);
private:
  string _value;
  bool _assignable = true;
  vector<string*> _memory={&_value};
};

#endif
