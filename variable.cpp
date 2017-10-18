#include "variable.h"
#include <string>
#include "iostream"

using namespace std;

/*Variable::Variable(string s):_symbol(s),_value(s){

}*/

string Variable::symbol() const{
  return _symbol;
}

string Variable::value() const{
  return _value;
}

bool Variable::checkassign(){
  return _assignable; //確認指派
}

void Variable::notassign(){
   _assignable=false;
}

/*bool Variable::match(string s){
  bool r = _assignable;

  if(_assignable){
    _value = s ;
    notassign();

  }else{
    r = (_value == s);
  }

  return r;
}*/

void Variable::change(string s){
  for(int i=0 ; i<_memory.size() ; i++){
    *_memory[i] =s;
  }
}

bool Variable::match( Number& num){
  bool r = _assignable;
 if(_assignable){
   _value = num.value() ;
   notassign();
 }else{
   r = (_value == num.value());
 }
 change(num.value());
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
  change(atom.symbol());
  return r;
}

bool Variable::match(Variable& x){
  bool result=_assignable;

  if(_assignable&&x._assignable){
    /*string *tmp=x._value;
    cout<<tmp<<endl;*/
    /*result=true;
    _memory.push_back(&x._value);
    //x._memory.push_back(&);
    _value=x._value;
    notassign();
    x.notassign();*/
    _memory.push_back(&x._value);
    x._memory.push_back(&_value);
    notassign();
    x.notassign();

  }else if(_assignable&&!x._assignable){

    /*result=true;
    _value=x._value;

    change(x._value);
    notassign();*/
    //_memory.push_back(&x._value);
    _memory.push_back(&x._value);
    x._memory.push_back(&_value);
    change(x._value);
    notassign();
  }else if(!_assignable&&x._assignable){
    /*result=true;
    x._value=_value;


    change(x._value);*/
    /*for(int i=0 ; i<_memory.size() ; i++){
      *x._memory.push_back(*_memory[i]);
    }*/

    //x.notassign();

  }else{
    //  result=(_value==x.value());
  }
  return result;
}
