#ifndef LIST_H
#define LIST_H

#include "term.h"

#include <vector>
#include <string>
using namespace std;

class List : public Term {
public:
  string symbol() const{
    if(_elements.size() == 0){
        return "[]";
    }else{
      string s="[";
      for(int i=0;i<_elements.size()-1;i++){
        s+=_elements[i]->symbol()+",";
      }
      s+=_elements[_elements.size()-1]->symbol()+"]";
      return s;
    }
    //return _symbol;
  }
  string value() const{return symbol();}
  bool match(Term & term){};
  List (): _elements(){}

  List (vector<Term *>  & elements):_elements(elements){}
  Term * head() const{};
  List * tail() const{};

private:
  vector<Term *> _elements;

};

#endif
