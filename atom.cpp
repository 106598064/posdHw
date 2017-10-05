#include "atom.h"
#include "number.h"
#include <string>
using namespace std;

Atom::Atom(string s):_symbol(s){

}

string Atom::symbol(){
  return _symbol;
}

bool Atom::match( Number& num){
    return false;
}

bool Atom::match(Atom& atom){
  if (atom.symbol()==_symbol){
    return true;
  }else{
    return false;
  }
}



bool Atom::match( Variable& x){
  if(x.checkassign()){
    x.notassign();
    x.match(symbol());
    return true;
  }else{
    return (_symbol==x.value());
  }
}
