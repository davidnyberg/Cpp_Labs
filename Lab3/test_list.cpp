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
  Sorted_List list{};
  CHECK(list.is_empty());
  CHECK(list.size() == 0);
}

TEST_CASE( "Create a non empty list") {
  Sorted_List list{5, 3 ,2};
  CHECK_FALSE( list.is_empty());
  CHECK(list.size() == 3);
}

TEST_CASE( "Test insert function" ){
    Sorted_List list{};
    list.insert(5);
    CHECK_FALSE( list.is_empty());
    CHECK( list.size() == 1 );
}

TEST_CASE( "Test remove function" ){
  Sorted_List list{};
  list.insert(5);
  CHECK_FALSE( list.is_empty());
  list.remove();
  CHECK(list.is_empty());

  //test edge case when list is empty
  CHECK_THROWS(list.remove());
}

//doesnt work yet
TEST_CASE("Testing copy assignment") {
  Sorted_List list{5};
  Sorted_List list2{};

  list2 = list;
  CHECK_FALSE(list2.is_empty());
}

TEST_CASE("Test print function") {
  //Sorted_List empty_list{};
  //empty_list.print_list();
  Sorted_List list{3};
  list.print_list();
  list.insert(5);
  list.print_list();
  list.insert(7);
  list.print_list();
  //std::cout << list.size() << std::endl;
}
