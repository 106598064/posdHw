#ifndef TERM_H
#define TERM_H

#include <string>
#include <vector>
#include <sstream>
#include <typeinfo>
//#include "atom.h"
//#include "variable.h"
template <class T>
class Iterator;
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
  virtual Iterator<Term *> * createIterator();
  virtual Iterator<Term *> * createDFSIterator();
  virtual Iterator<Term *> * createBFSIterator();
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
