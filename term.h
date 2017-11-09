#ifndef TERM_H
#define TERM_H

#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
//#include "atom.h"
//#include "variable.h"
class Variable;

using namespace std;

class Term{
public:
  virtual string symbol() const {return _symbol;}
  virtual string value() const {return symbol();}
  virtual int arity() const{return 0;}
  virtual bool match(Term & a);
  virtual Term * args(int index) {return 0;}
  virtual vector<Term*> elements(){};
protected:
  Term ():_symbol(""){}
  Term (string s):_symbol(s) {}
  Term(double db){
    std::ostringstream strs;
    strs << db;
    _symbol = strs.str();
  }
  string _symbol;
};

#endif
