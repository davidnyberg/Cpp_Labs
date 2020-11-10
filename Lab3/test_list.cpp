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
#include <string>
#include <random>

//=======================================================================
// Test cases
//=======================================================================
// It is your job to create new test cases and fully test your Sorted_List class

//TODO: Complementary work needed, testing both versions of copy/move
//should include modifying a list and show that the other is not
//affected (hard copy).
//DONE

TEST_CASE( "Create an empty list" ) {
  Sorted_List list{};
  CHECK(list.is_empty());
  CHECK(list.size() == 0);
}

TEST_CASE( "Create a non empty list") {
  Sorted_List list{2, 3};
  CHECK_FALSE( list.is_empty());
  CHECK(list.size() == 2);
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
  list.remove(5);
  CHECK(list.is_empty());

  //test edge case when list is empty
  CHECK_THROWS(list.remove(5));

  Sorted_List list1{1,2,3,4,5};
  list1.remove(5);
  CHECK(list1.print_list() == "1234");
  list1.remove(1);
  CHECK(list1.print_list() == "234");
  //test remove something not in list, no change to list
  list1.remove(10);
  CHECK(list1.print_list() == "234");
}

TEST_CASE("Test print function") {
  std::string correct = "";
  std::string v = "";

  Sorted_List empty_list{};
  v = empty_list.print_list();
  CHECK(v == correct);

  Sorted_List list{3};
  correct += "3";
  v = list.print_list();
  CHECK(v == correct);

  list.insert(7);
  correct += "7";
  v = list.print_list();
  CHECK(v == correct);

  list.insert(1);
  correct = "137";
  v = list.print_list();
  CHECK(v == correct);

  list.insert(5);
  correct = "1357";
  v = list.print_list();
  CHECK(v == correct);

  list.remove(1);
  list.remove(3);
  list.remove(5);
  list.remove(7);
  CHECK("" == list.print_list());
}

TEST_CASE("MOVE OPERATOR"){
    Sorted_List list{2,3};
    Sorted_List list2{};

    std::cout << "Should call move: ";
    list2 = std::move(list);
    CHECK(list.is_empty());
    CHECK_FALSE(list2.is_empty());

   //Completion work, shows changing a copied list is not affecting the copier
    list2.insert(5);
    list.insert(1);
    CHECK(list2.print_list() == "235");
    CHECK(list.print_list() == "1");

}

TEST_CASE("COPY OPERATOR"){
    Sorted_List list2{1,2};
    Sorted_List list{2,3,4};

    CHECK_FALSE(list.size() == list2.size());

    std::cout << "Should call copy: ";
    list2 = list;

    CHECK_FALSE(list.is_empty());
    CHECK_FALSE(list2.is_empty());
    CHECK(list.size() == list2.size());
    CHECK(list2.print_list() == list.print_list());

    //Completion work, shows changing a copied list is not affecting the copier
    list2.insert(5);
    CHECK(list2.print_list() == "2345");
    CHECK(list.print_list() == "234");

    list.insert(9);
    CHECK(list2.print_list() == "2345");
    CHECK(list.print_list() == "2349");

}

TEST_CASE("Copy constructor") {
    Sorted_List old_list{1,2,3};
    std::cout << "Should call copy constructor: ";
    Sorted_List new_list{ old_list }; 

    CHECK_FALSE(old_list.is_empty());
    CHECK(new_list.size() == 3);
    CHECK(old_list.size() == 3);

    //Completion work, shows changing a copied list is not affecting the copier
    old_list.insert(9);
    CHECK(old_list.print_list() == "1239");
    CHECK(new_list.print_list() == "123");

    new_list.insert(4);
    CHECK(old_list.print_list() == "1239");
    CHECK(new_list.print_list() == "1234");
}

TEST_CASE("Move constructor") {
  Sorted_List old_list{1,2,3};

  std::cout << "Should call move constructor: ";
  Sorted_List new_list{ std::move(old_list) }; 
  CHECK(old_list.is_empty());
  CHECK(new_list.size() == 3);

    //Completion work, shows changing a copied list is not affecting the copier
    old_list.insert(9);
    CHECK(old_list.print_list() == "9");
    CHECK(new_list.print_list() == "123");

    new_list.insert(4);
    CHECK(old_list.print_list() == "9");
    CHECK(new_list.print_list() == "1234");
}
