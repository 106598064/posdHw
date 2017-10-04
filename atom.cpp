#include "atom.h"

#include <string>
using namespace std;

Atom::Atom(string s):_symbol(s){

}

string Atom::symbol(){
  return _symbol;
}

bool Atom::match(Number num){
  if (num.symbol()==_symbol){
    return true;
  }else{
    return false;
  }
}



bool Atom::match( Variable &x){
  if(x.checkassign()){
    x.notassign();
    //x.match(symbol());
    x.match(*this);
    return true;
  }else{
    return (_symbol==x.value());
  }
}
