// jugador_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include <iostream>
#include "counter.h"
#include "gtest/gtest.h"

TEST(Counter, Constructor) {
  Counter c;
  EXPECT_EQ(0, c.Get());
  Counter d(10);
  EXPECT_EQ(10, d.Get());
  Counter d1(-5);
  EXPECT_EQ(0, d1.Get());
  Counter d2(4000);
  EXPECT_EQ(0, d2.Get());
  Counter e(-3,10,20);
  EXPECT_EQ(0, e.Get());
  Counter f(10,20,15);
  EXPECT_EQ(0, f.Get());
  Counter g(-10,200,55);
  EXPECT_EQ(0, g.Get());
  Counter h(-10,200,-3);
  EXPECT_EQ(0, h.Get());
  Counter i(10,-200,55);
  EXPECT_EQ(10, i.Get());
  Counter j(250,200,300);
  EXPECT_EQ(250, j.Get());
  Counter k(-300,-300,200);
  EXPECT_EQ(-300, k.Get());
}

TEST(Counter, IncrementoPostfijo1) {
  Counter c;
  EXPECT_EQ(0, c.Get());
  c++;
  EXPECT_EQ(1, c.Get());
  c++;
  EXPECT_EQ(2, c.Get());
}

TEST(Counter, IncrementoPostfijo2) {
  Counter c(1,10,9);
  EXPECT_EQ(0, c.Get());
  c++;
  c++;
  EXPECT_EQ(2, c.Get());
}

TEST(Counter, IncrementoPostfijo3) {
  Counter c(99,10,100);
  EXPECT_EQ(99, c.Get());
  c++;
  EXPECT_EQ(100, c.Get());
  c++;
  EXPECT_EQ(100, c.Get());
}

TEST(Counter, IncrementoPrefijo1) {
  Counter c;
  EXPECT_EQ(0, c.Get());
  ++c;
  EXPECT_EQ(1, c.Get());
  ++c;
  EXPECT_EQ(2, c.Get());
}

TEST(Counter, IncrementoPrefijo2) {
  Counter c(1,10,9);
  EXPECT_EQ(0, c.Get());
  ++c;
  ++c;
  EXPECT_EQ(2, c.Get());
}

TEST(Counter, IncrementoPrefijo3) {
  Counter c(99,10,100);
  EXPECT_EQ(99, c.Get());
  ++c;
  EXPECT_EQ(100, c.Get());
  ++c;
  EXPECT_EQ(100, c.Get());
}

TEST(Counter, DecrementoPostfijo1) {
  Counter c;
  EXPECT_EQ(0, c.Get());
  c--;
  EXPECT_EQ(0, c.Get());
}

TEST(Counter, DecrementoPostfijo2) {
  Counter c(1,10,10);
  EXPECT_EQ(0, c.Get());
  c--;
  EXPECT_EQ(0, c.Get());
  c--;
  EXPECT_EQ(0, c.Get());
  c++;
  EXPECT_EQ(1, c.Get());
  c++;
  EXPECT_EQ(2, c.Get());
  c--;
  EXPECT_EQ(1, c.Get());
}

TEST(Counter, DecrementoPostfijo3) {
  Counter c(1,10,2);
  EXPECT_EQ(0, c.Get());
  c--;
  c--;
  EXPECT_EQ(0, c.Get());
}

TEST(Counter, DecrementoPrefijo1) {
  Counter c;
  EXPECT_EQ(0, c.Get());
  --c;
  EXPECT_EQ(0, c.Get());
}

TEST(Counter, DecrementoPrefijo2) {
  Counter c(1,10,10);
  EXPECT_EQ(0, c.Get());
  --c;
  EXPECT_EQ(0, c.Get());
  --c;
  EXPECT_EQ(0, c.Get());
}

TEST(Counter, DecrementoPrefijo3) {
  Counter c(11,10,200);
  EXPECT_EQ(11, c.Get());
  --c;
  EXPECT_EQ(10, c.Get());
  --c;
  EXPECT_EQ(10, c.Get());
}


TEST(Counter, Asignacion1) {
  Counter c;
  c=10;
  EXPECT_EQ(10, c.Get());
  c=5000;
  EXPECT_EQ(1000, c.Get());
  c=-3000;
  EXPECT_EQ(0, c.Get());
}

TEST(Counter, Asignacion2) {
  Counter c;  
  c=5555;
  EXPECT_EQ(1000, c.Get());
  c=-55555;
  EXPECT_EQ(0, c.Get());
}

TEST(Counter, Asignacion3) {
  Counter c, d;
  c=10;
  d=c;
  EXPECT_EQ(10, d.Get());
}

TEST(Counter, DevolucionUnarioPrefijo) {
  Counter c, d;
  c=10;
  EXPECT_EQ(10, c.Get());
  d=++c;
  EXPECT_EQ(11, c.Get());
  EXPECT_EQ(11, d.Get());
  d=--c;
  EXPECT_EQ(10, c.Get());
  EXPECT_EQ(10, d.Get());
}

TEST(Counter, DevolucionUnarioPostfijo) {
  Counter c, d;
  c=10;
  EXPECT_EQ(10, c.Get());
  d=c++;
  EXPECT_EQ(11, c.Get());
  EXPECT_EQ(10, d.Get());
  d=c--;
  EXPECT_EQ(10, c.Get());
  EXPECT_EQ(11, d.Get());
}


TEST(Counter, Suma1) {
  Counter c,d;
  c=d+10;
  EXPECT_EQ(10, c.Get());
  c=c+15;
  EXPECT_EQ(25, c.Get());
}

TEST(Counter, Suma2) {
  Counter c,d;
  c=10+d;
  EXPECT_EQ(10, c.Get());
  c=15+c;
  EXPECT_EQ(25, c.Get());
}

TEST(Counter, Suma3) {
  Counter c,d;
  c=d+5555;
  EXPECT_EQ(1000, c.Get());
  c=5555+d;
  EXPECT_EQ(1000, c.Get());

  Counter e(1000,3000,2000);
  e=e+5000;
  EXPECT_EQ(1000, e.Get());
  e=5000+e;
  EXPECT_EQ(1000, e.Get());
}

TEST(Counter, Resta1) {
  Counter c(1,100,10), d(1,100,10);
  c=d-5;
  EXPECT_EQ(0, c.Get());
  c=c-1;
  EXPECT_EQ(0, c.Get());
}

TEST(Counter, Resta2) {
  Counter c(10,10,100), d(10,10,100);
  c=d-5;
  EXPECT_EQ(10, c.Get());
  c=c-1;
  EXPECT_EQ(10, c.Get());
}

TEST(Counter, Resta3) {
  Counter c(100,1,1000), d(100,1,1000);
  c=d-5;
  EXPECT_EQ(95, c.Get());
  c=c-1;
  EXPECT_EQ(94, c.Get());
}


TEST(Counter, Resta4) {
  Counter c(10,10,100), d(10,10,100);
  c=15-d;
  EXPECT_EQ(10, c.Get());
  c=9-c;
  EXPECT_EQ(10, c.Get());
}

TEST(Counter, Resta5) {
  Counter c(10000,1,1000000), d(10000,1,1000000);
  c=d-5555;
  EXPECT_EQ(4445, c.Get());
  c=1-d;
  EXPECT_EQ(1, c.Get());
}

TEST(Counter, ConstructorErroneo) {
  Counter c(10,-200,55);
  EXPECT_EQ(10, c.Get());
  c=-5000;  
  EXPECT_EQ(-200, c.Get()); 
  c=5000;
  EXPECT_EQ(55, c.Get());
  Counter d(10,200,300);
  EXPECT_EQ(0, d.Get());
  Counter e(10,200,-300);
  EXPECT_EQ(0, e.Get());
}

TEST(Counter, InsertadorPropio) {
  Counter c(10,-200,55);
  EXPECT_EQ(10, c.Get());
  std::cout << c;
}

TEST(Counter, ExtractorPropio) {
  Counter c(10,10,20);
  EXPECT_EQ(10, c.Get());
  std::cin >> c;
  std::cout << "OK - Valor del Counter: " << c;
}