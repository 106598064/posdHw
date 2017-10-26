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
  virtual string symbol() const{return _symbol;}
  virtual string value() const{return symbol();}
  virtual bool match(Term & a);//{
    /*if (typeid(a) ==  typeid(Variable))
      return a.match(*this);
    else*/
      //return symbol() == a.symbol();
  //}
  virtual vector<Term*> elements(){};
protected:
  Term ();
  Term (string s);
  Term(double db);
  string _symbol;
};

#endif