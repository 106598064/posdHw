#ifndef UTLIST_H
#define UTLIST_H

#include <string>
#include <vector>
using namespace std;

#include "list.h"
#include "term.h"
#include "struct.h"
#include "atom.h"
#include "variable.h"

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
  List L;
  EXPECT_EQ("[]",L.symbol());
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
  Number n1(496);
  Number n2(8128);
  vector<Term *> args = {&n1, &n2};
  List L(args);
  EXPECT_EQ(string("[496, 8128]"),L.symbol());
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
  Atom t1("terence_tao");
  Atom t2("alan_mathison_turing");
  vector<Term *> args = {&t1, &t2};
  List L(args);
  EXPECT_EQ(string("[terence_tao, alan_mathison_turing]"),L.symbol());
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
  Variable x("X");
  Variable y("Y");
  vector<Term *> args = {&x, &y};
  List L(args);
  EXPECT_EQ(string("[X, Y]"),L.symbol());
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
  Variable x("X");
  Atom t1("terence_tao");
  Atom t2("tom");
  Number n(496);
  vector<Term *> args = {&n, &x, &t1};
  List L(args);
  //cout<<L.symbol()<<endl;
  EXPECT_FALSE(L.match(t2));
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
  Variable x("X");
  Atom t1("terence_tao");
  Number n1(496);
  Number n2(8128);
  vector<Term *> args = {&n1, &x, &t1};
  List L(args);
  EXPECT_FALSE(L.match(n2));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
  Variable x("X");
  vector<Term *> args={&x};
  Struct s(Atom("s"),args);
  Number n(496);
  Atom t("terence_tao");
  vector<Term *> args2 = {&x,&t,&n};
  List L(args2);
  EXPECT_FALSE(L.match(s));
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
  Variable x("X");
  Number n(496);
  Atom t("terence_tao");
  vector<Term *> args = {&n,&x,&t};
  List L(args);
  Variable y("Y");
  EXPECT_TRUE(L.match(y));
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail) {
  Variable x("X");
  Number n(496);
  Atom t("terence_tao");
  vector<Term *> args = {&n,&x,&t};
  List L(args);
  EXPECT_TRUE(L.match(x));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
  Variable x("X");
  Number n(496);
  Atom t("terence_tao");
  vector<Term *> args = {&n,&x,&t};
  List L(args);
  EXPECT_TRUE(L.match(L));
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
  Variable x("X");
  Number n(496);
  Atom t("terence_tao");
  vector<Term *> args1 = {&n,&x,&t};
  List L1(args1);
  Variable y("Y");
  vector<Term *> args2 = {&n,&y,&t};
  List L2(args2);
  EXPECT_TRUE(L1.match(L2));
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {
  Variable x("X");
  Number n1(496);
  Atom t("terence_tao");
  vector<Term *> args1 = {&n1,&x,&t};
  List L1(args1);
  Number n2(8128);
  vector<Term *> args2 = {&n1,&n2,&t};
  List L2(args2);
  EXPECT_TRUE(L1.match(L2));
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {
  Variable x("X");
  Number n(496);
  Atom t1("terence_tao");
  vector<Term *> args = {&n,&x,&t1};
  List L(args);
  Variable y("Y");
  Atom t2("alan_mathison_turing");
  EXPECT_TRUE(L.match(y));
  EXPECT_TRUE(x.match(t2));
}

// Example:
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("first"), l.head()->symbol());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {
  Atom f("[first]"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);
  EXPECT_EQ(string("[first]"), l.head()->symbol());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);
  EXPECT_EQ(string("third"),  l.tail()->tail()->head()->value());
  EXPECT_EQ(string("[]"),  l.tail()->tail()->tail()->value());
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {
  vector<Term *> args;
  List l(args);
  try
  {
    l.head()->symbol();
  }
  catch(string e)
  {

  }
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {
  vector<Term *> args;
  List l(args);
  try
  {
    l.head()->symbol();
  }
  catch(string e)
  {

  }
  catch(string *e){

  }
}




#endif
