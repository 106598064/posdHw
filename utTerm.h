#ifndef UTTERM_H
#define UTTERM_H
#include "atom.h"
#include "variable.h"
#include "number.h"
#include <iostream>

//test Number.value()
TEST (Number,ctor) {
  Number n(100);
  EXPECT_EQ("100",n.value());
}
//test Number.symbol()
TEST (Number, symbol) {
  Number n(100);
  EXPECT_EQ("100",n.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
  Number n1(25);
  Number n2(25);
  EXPECT_TRUE(n1.match(n2));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
  Number n1(25);
  Number n2(0);
  EXPECT_FALSE(n1.match(n2));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
  Number n(25);
  Atom tom("tom");
  EXPECT_FALSE(n.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
  Number n(25);
  Variable x("X");
  EXPECT_TRUE(n.match(x));

}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
  Atom tom("tom");
  Number n(25);
  EXPECT_FALSE(tom.match(n));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
  Variable x("X");
  Atom tom("tom");
  EXPECT_TRUE(tom.match(x));
  EXPECT_EQ("tom",x.value());

}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
  Variable x("X");
  Atom tom("tom");
  x.match(tom);
  EXPECT_TRUE(tom.match(x));
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
  Atom jerry("jerry");
  Atom tom("tom");
  Variable x("X");
  x.match(jerry);
  EXPECT_FALSE(tom.match(x));
}





// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
  Number n(5);
  Variable x("X");
  EXPECT_TRUE(x.match(n));
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
    Number n1(25);
    Number n2(100);
    Variable x("X");
    x.match(n1);
    EXPECT_FALSE(x.match(n2));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
    Number n(25);
    Variable x("X");
    Atom tom("tom");
    x.match(tom);
    EXPECT_FALSE(x.match(n));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
    Number n(25);
    Variable x("X");
    Atom tom("tom");
    tom.match(x);
    EXPECT_FALSE(n.match(x));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
    Variable x("X");
    Atom tom("tom");
    x.match(tom);
    EXPECT_TRUE(x.match(tom));

}
#endif
