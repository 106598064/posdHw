#include "number.h"
//#include "atom.h"
#include "iostream"
#include<string>
#include<sstream>
using namespace std;

Number::Number(double v):_value(v),_symbol(to_string(v)){

}

string Number::symbol(){
  return _symbol;
}

string Number::value(){
  //return to_string(_value);
  ostringstream strs;
  strs << _value;
  string str = strs.str();
  //cout<<str<<endl;
  return str;
}

bool Number::match(Atom& atom){
  return false;
}

bool Number::match(Variable& x){
  /*if(x.checkassign()){
    x.match(value());
    x.notassign();
    return true;
  }else{
    return (value()==x.value());
  }*/
}

bool Number::match(Number& num){
  if(_value==num._value){
    return true;
  }else{
    return false;
  }
}
