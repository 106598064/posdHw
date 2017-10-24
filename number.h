#ifndef NUMBER_H
#define NUMBER_H


#include <string>
#include <sstream>
#include "term.h"
using namespace std;

class Number : public Term{
public:
  Number(double a){
    ostringstream strs;
    strs << a;
    _symbol = strs.str();
  }
};


#endif
