#include "number.h"
#include<string>
using namespace std;

Number::Number(int v):_value(v),_symbol(to_string(v)){

}

string Number::symbol(){
  return _symbol;
}

string Number::value(){
  return to_string(_value);
}

bool Number::match(Atom atom){
  return false;
}

bool Number::match(Variable& x){
  if(x.checkassign()){
    x.notassign();
    x.match(value());
    return true;
  }else{
    return (value()==x.value());
  }
}

bool Number::match(Number num){
  if(_value==num._value){
    return true;
  }else{
    return false;
  }
}
