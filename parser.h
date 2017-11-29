#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"
#include "node.h"
#include "number.h"
#include "utParser.h"
#include <iostream>

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner), _terms(){}

  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }

    return nullptr;
  }



  Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }

  vector<Term *> & getTerms() {
    return _terms;
  }

  void matchings(){
    Term* term = createTerm();
    if(term!=nullptr){
      if(commaflag){
        //_term.match(term);
        //cout<<_terms.size()<<endl;
        for(int i=0;i<_terms.size();i++){
          //cout<<term->symbol()<<endl;
          if(_terms[i]->value()==term->value()){
            term->match(*_terms[i]);
          }
          Struct * st = dynamic_cast<Struct*>(_terms[i]);
          if(st){
              StructSearch(st,term);
          }
        }
      }
      _terms.push_back(term);
      //_currentToken = _scanner.nextToken();
      while((_currentToken = _scanner.nextToken()) == ','||  _currentToken=='='||_currentToken == ';') {
        if(_currentToken == '='){
          Node * l=new Node(TERM,_terms.back(),nullptr,nullptr);
          _terms.push_back(createTerm());
          Node * r=new Node(TERM,_terms.back(),nullptr,nullptr);
          Node * root=new Node(EQUALITY,nullptr,l,r);
          _CurrentTreeRoot=root;
          Struct * st = dynamic_cast<Struct*>(_terms[_terms.size()-1]);
          if(_terms.size()>=6&&st){
            StructSearch(st,_terms[_terms.size()-4]);
          }
        }else if(_currentToken == ','){
          //cout<<"sss"<<endl;
          commaflag=true;
          Node * l=expressionTree();
          matchings();
          Node * root=new Node(COMMA,nullptr,l,_CurrentTreeRoot);
          _CurrentTreeRoot=root;

        }else{
          //cout<<"hhh"<<endl;
          Node * l=expressionTree();
          matchings();
          Node * root=new Node(SEMICOLON,nullptr,l,_CurrentTreeRoot);
          _CurrentTreeRoot=root;
        }
      }
    }
  }

  Node * expressionTree(){
    return _CurrentTreeRoot;
  }

  void StructSearch(Struct *st,Term *term){
    //cout<<"ccc"<<endl;
    for(int i=0;i<st->arity();i++){
      if(st->args(i)->value()==term->value()){
        //cout<<st->args(i)->value()<<endl;
        st->args(i)->match(*term);
      }
      Struct * st2 = dynamic_cast<Struct*>(st->args(i));
      if(st2){
        StructSearch(st2,term);
      }
    }
  }

private:
  FRIEND_TEST(ParserTest, createArgs);
  FRIEND_TEST(ParserTest,ListOfTermsEmpty);
  FRIEND_TEST(ParserTest,listofTermsTwoNumber);
  FRIEND_TEST(ParserTest, createTerm_nestedStruct3);

  void createTerms() {
    Term* term = createTerm();
    if(term!=nullptr)
    {
      _terms.push_back(term);
      while((_currentToken = _scanner.nextToken()) == ',') {
        _terms.push_back(createTerm());
      }
    }
  }

  vector<Term *> _terms;
  Scanner _scanner;
  int _currentToken;
  Node * _CurrentTreeRoot;
  bool commaflag=false;
};
#endif
