#include "term.h"
#include "variable.h"
#include <string>
#include <sstream>
#include <typeinfo>
#include "list.h"
#include <iostream>

using namespace std;

//string Term::symbol() const {return _symbol;}
//string Term::value() const {return symbol();}
bool Term::match(Term & a){
  if (typeid(a) ==  typeid(Variable))
    return a.match(*this);
  /*else if(typeid(a) ==  typeid(List)){
    cout<<"sss"<<endl;
    return false;
    
  }*/
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
