#ifndef ATOM_H
#define ATOM_H

#include <string>
using namespace std;


class Term{

public:
  virtual string symbol() const= 0;

  virtual string value() const{
    return symbol();
  };

  virtual bool match(Term & term) {
    return symbol() == term.symbol();
  }

  string _type;
  //string  *_value;
};

class Atom : public Term{
public:
  Atom (string s):_symbol(s) {}

  string symbol() const{
    return _symbol;
  }

  bool match(Term & term){
    if(term._type=="var")
    {
      //*(term._value)=symbol();
      return true;
    }
    else Term::match(term);
  }


  string _symbol;
};


#endif
