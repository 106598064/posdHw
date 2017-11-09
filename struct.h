#ifndef STRUCT_H
#define STRUCT_H

#include "term.h"
#include "atom.h"
#include <vector>
#include <string>

using namespace std;

class Struct: public Term {
public:
  Struct(Atom name, std::vector<Term *> args): _name(name) {
    _args = args;
  }

  Term * args(int index) {
    return _args[index];
  }

  Atom & name() {
    return _name;
  }
  string symbol() const {
    if(_args.size()>0){
      string ret = _name.symbol() + "(";
      std::vector<Term *>::const_iterator it = _args.begin();
      for (; it != _args.end()-1; ++it)
        ret += (*it)->symbol()+", ";
      ret  += (*it)->symbol()+")";
      return ret;
    }else{
      return _name.symbol()+"()";
    }

  }
  string value() const {
    if(_args.size()>0){
      string ret = _name.symbol() + "(";
      std::vector<Term *>::const_iterator it = _args.begin();
      for (; it != _args.end()-1; ++it)
        ret += (*it)->value()+", ";
      ret  += (*it)->value()+")";
      return ret;
    }else{
      return _name.symbol()+"()";
    }

  }
  int arity() const{
    return _args.size();
  }
private:
  Atom _name;
  std::vector<Term *> _args;
};

#endif
