#ifndef ATOM_H
#define ATOM_H

#include <string>
//#include <sstream>
#include "term.h"
using namespace std;

class Atom : public Term{
public:
  Atom(string s);//{_symbol = s; }
//private:
  //string _symbol;
};

#endif
