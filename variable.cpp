#include "variable.h"
#include <string>
using namespace std;

Variable::Variable(string s):_value(s){

}

string Variable::value(){
  return _value;
}

bool Variable::checkassign(){
  return _assignable; //確認指派
}

void Variable::notassign(){
   _assignable=false;

}

bool Variable::match(string s){
  bool r = _assignable;
    if(_assignable){
      _value = s ;
      notassign();
    }else{
      r = (_value == s);
    }
    return r;
}

bool Variable::match( Number& num){
  bool r = _assignable;
    if(_assignable){
      _value = num.value() ;
      notassign();
    }else{
      r = (_value == num.value());
    }
    return r;
}

bool Variable::match(Atom& atom){
  bool r = _assignable;
  if(_assignable){
    _value = atom.symbol();
    notassign();
  }else{
    r = (_value == atom.symbol());
  }
  return r;
}
