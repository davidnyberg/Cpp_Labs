// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Code:
// https://github.com/philsquared/Catch.git
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// You ARE however required to implement all test cases outlined here,
// even if you do it by way of your own function for each case.  You
// are recommended to solve the cases in order, and rerun all tests
// after you modify your code.

// This define lets Catch create the main test program
// (Must be in only one place!)
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "linkedlist.hpp"

#include <random>

//=======================================================================
// Test cases
//=======================================================================
// It is your job to create new test cases and fully test your Sorted_List class
TEST_CASE( "Create an empty list" ) {
  Sorted_List l{};
  CHECK(l.is_empty());
  CHECK(l.size() == 0);
}

TEST_CASE( "Create a non empty list") {
  Sorted_List l{5, 3 ,2};
  CHECK_FALSE( l.is_empty());
  CHECK(l.size() == 3);
}

TEST_CASE( "Test insert function" ){
    Sorted_List l{};
    l.insert(5);
    CHECK_FALSE( l.is_empty());
    CHECK( l.size() == 1 );
}

TEST_CASE( "Test remove function" ){
  Sorted_List l{};
  l.insert(5);
  CHECK_FALSE( l.is_empty());
  l.remove();
  CHECK(l.is_empty());

  //test edge case when l is empty
  CHECK_THROWS(l.remove());
}


//doesnt work yet
TEST_CASE("Testing copy assignment") {
  Sorted_List l{5};
  Sorted_List l2{};

  l2 = l;
  //CHECK_FALSE(l2.is_empty());
}
