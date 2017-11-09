#ifndef PARSER_H
#define PARSER_H
#include <string>
using namespace std;

#include "term.h"
#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "iostream"
#include "list.h"
#include "number.h"

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken=token;
    if(token == VAR){
      //cout<<"sss"<<endl;
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM||token == ATOMSC){
        Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
        if(_scanner.currentChar() == '(' ) {
          _scanner.nextToken() ;
          vector<Term*> terms = getArgs();
          if(_currentToken == ')')
            return new Struct(*atom, terms);
        }
        else
          return atom;
    }else if(token == '['){
      //cout<<"sss"<<endl;
      vector<Term*> terms = getArgs();
      if(_currentToken==']'){
        return new List(terms);
      }else if(_currentToken==')'){
        throw string("unexpected token");
      }
    }
    return nullptr;
  }

  vector<Term*> getArgs()
  {
    Term* term = createTerm();
    vector<Term*> args;
    if(term)
      args.push_back(term);
    if((_currentToken!=']' ||term!=nullptr) && (_currentToken!=')'||term!=nullptr)){
      while((_currentToken = _scanner.nextToken()) == ',') {
        args.push_back(createTerm());
      }
    }

    return args;
  }



private:
  Scanner _scanner;
  int _currentToken;
};
#endif
