#ifndef LIST_H
#define LIST_H

#include "atom.h"
#include "variable.h"
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
using namespace std;

class List : public Term {
public:
  string symbol() const{
    if(_elements.size() == 0){
        return "[]";
    }else{
      string s="[";
      for(int i=0;i<_elements.size()-1;i++){
        s+=_elements[i]->value()+", ";
      }
      s+=_elements[_elements.size()-1]->value()+"]";
      return s;
    }
    //return _symbol;
  }
  string value() const{return symbol();}
  bool match(Term & term){
    //cout<<"sss"<<endl;
    if (typeid(term) ==  typeid(Variable))
    {
      return term.match(*this);

    }else if(typeid(term) ==  typeid(List)){
      if(_elements.size()!=term.elements().size()){
        return false;
      }else{
        for(int i=0;i<_elements.size();i++){
          if(!_elements[i]->match(*term.elements()[i])){
            return false;
          }else{
            //*_elements[i]=*term.elements()[i];
          }
        }
        return true;
      }
      //return symbol() == term.symbol();
    }else{
      return symbol() == term.symbol();
    }
    /*if(_elements.size()!=term.symbol().size()){
      return false;
    }*/
  };
  List (): _elements(){}

  List (vector<Term *> &elements):_elements(elements){}
  Term * head() const{
    if(_elements.size()==0){
      throw string("Accessing head in an empty list");
    }else{
      return _elements[0];
    }
  };
  List * tail() const{
    if(_elements.size()==0){
      throw string("Accessing tail in an empty list");
    }else{
      List *tmplist=new List();
      tmplist->_elements=_elements;
      tmplist->_elements.erase(tmplist->_elements.begin());
      return tmplist;
    }
  };

  vector<Term *> elements(){
    return _elements;
  }

private:
  vector<Term *> _elements;

};

#endif
