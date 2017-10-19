#ifndef UTVARIABLE_H
#define UTVARIABLE_H
#include "variable.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "iostream"

using namespace std;

TEST(Variable, constructor){
  Variable X("X");
  ASSERT_EQ("X", X._symbol);
}

TEST(Variable , matching){
  Atom tom("tom");
  Variable X("X");
  X.match(tom);
  ASSERT_EQ( "tom", X.value());
}

TEST (Variable , haveValue){
  Atom tom ("tom");
  Atom jerry ("jerry");
  Variable X("X");
  ASSERT_TRUE(X.match(tom));
  ASSERT_FALSE(X.match(jerry));
  //cout<<X.value()<<endl;
}

// ?- X=2.7182.
// X=2.7182
TEST(Variable , numE_to_varX){
  Number n(2.7182);
  Variable x("X");
  x.match(n);
  EXPECT_EQ("2.7182",x.value());
  //cout<<x.value()<<endl;
}

// ?- X=Y, X=1.
// Y=1
TEST (Variable, varY_to_varX_and_num1_to_varX) {
  Variable x("X");
  Variable y("Y");
  Number n(1);
  x.match(y);
  x.match(n);
  EXPECT_EQ("1",y.value());
  //cout<<y.value()<<endl;
}


// ?- X=Y, Y=1.
// X=1
TEST (Variable, varY_to_varX_and_num1_to_varY) {
  Variable x("X");
  Variable y("Y");
  Number n(1);
  x.match(y);
  y.match(n);
  EXPECT_EQ("1",x.value());
}

// ?- X=X, X=1.
// X=1
TEST (Variable, varX_match_varX_and_num1_to_varX) {
  Variable x("X");
  Number n(1);
  x.match(x);
  x.match(n);
  EXPECT_EQ("1",x.value());
}

// ?- Y=1, X=Y.
// X=1
TEST (Variable, num1_to_varY_and_varX_match_varY) {
  Variable x("X");
  Variable y("Y");
  Number n(1);
  y.match(n);
  x.match(y);
  EXPECT_EQ("1",x.value());
}

// ?- X=Y, Y=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varY_to_varX) {
  Variable x("X");
  Variable y("Y");
  Variable z("Z");
  Number n(1);
  x.match(y);
  y.match(z);
  z.match(n);
  EXPECT_EQ("1",x.value());
  EXPECT_EQ("1",y.value());
  EXPECT_EQ("1",z.value());
}

// ?- X=Y, X=Z, Z=1
// X=1, Y=1, Z=1
TEST (Variable, num1_to_varZ_to_varX_and_varY_to_varX) {
  Variable x("X");
  Variable y("Y");
  Variable z("Z");
  Number n(1);
  x.match(y);
  x.match(z);
  z.match(n);
  EXPECT_EQ("1",x.value());
  EXPECT_EQ("1",y.value());
  EXPECT_EQ("1",z.value());
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(X)"
TEST (Variable, Struct1) {
  Variable x("X");
  Variable y("Y");
  vector<Term *> v={&x};
  Struct st(Atom("s"),v);
  y.match(st);
  ASSERT_EQ("Y", y.symbol());
  ASSERT_EQ("s(X)", y.value());
}

// Give there is a Struct s contains Variable X
// And another Variable Y
// When Y matches Struct s
// And X matches Atom "teddy"
// Then #symbol() of Y should return "Y"
// And #value() of Y should return "s(teddy)"
TEST (Variable, Struct2) {
  Variable x("X");
  Variable y("Y");
  Atom teddy("teddy");
  vector<Term *> v={&x};
  Struct st(Atom("s"),v);
  x.match(teddy);
  y.match(st);
  ASSERT_EQ("Y", y.symbol());
  ASSERT_EQ("s(teddy)", y.value());
}



#endif
