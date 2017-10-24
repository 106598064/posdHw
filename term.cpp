#include "term.h"
#include "variable.h"
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;

//string Term::symbol() const {return _symbol;}
//string Term::value() const {return symbol();}
bool Term::match(Term & a){
  if (typeid(a) ==  typeid(Variable))
    return a.match(*this);
  else
    return symbol() == a.symbol();
}
Term::Term ():_symbol(""){}
Term::Term (string s):_symbol(s) {}
Term::Term(double db){
  ostringstream strs;
  strs << db;
  _symbol = strs.str();
}
