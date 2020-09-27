#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.hpp"
#include <iostream>
#include <string>


TEST_CASE("INIT") {
    Time time;
    CHECK(time.hours == 0);
    CHECK(time.minutes == 0);
    CHECK(time.seconds == 0);
}

TEST_CASE("VALIDATE_TIME") {
    Time t;
    CHECK(isValid(t) == true);

    Time t1{10, 30, 30};
    CHECK(isValid(t) == true);
}

TEST_CASE("TO_STRING") {
    Time t{12, 30, 30};
    CHECK(toString(t, true) == "12:30:30");
    CHECK(toString(t, 1) == "12:30:30");
    CHECK(toString(t, 0) == "12:30:30 pm");
    Time t1{15, 50, 25};
    //Need to fix the 0 before the 3 in return
    CHECK(toString(t1, false) == "3:50:25 pm");
}

TEST_CASE("IS_AM") {
    Time t{15, 1, 1};
    CHECK(isAM(t) == false);
    Time t2{03,30,30};
    CHECK(isAM(t2) == true);
}

TEST_CASE("OPERATOR+") {
    Time t;
    Time new_t = t + 5;
    CHECK(new_t.seconds == 05);
    //check that original t is unchanged
    CHECK(t.seconds == 0);

    Time t2{1,1,1};
    Time t3{5,5,5};
    Time add_res{6, 6, 6};
    CHECK(t2 + t3 == add_res);
}

TEST_CASE("OPERATOR-") {
    Time t{10,10,10};
    Time new_t = t - 5;
    CHECK(new_t.seconds == 05);
    //check that original t is unchanged
    CHECK(t.seconds == 10);

    Time t2{1,1,1};
    Time t3{5,5,5};
    Time sub_res{4, 4, 4};
    CHECK(t3 - t2 == sub_res);
}

TEST_CASE("OPERATOR==") {
    Time t{12,12,12};
    Time t1{12,12,12};
    Time t2{};
    CHECK((t == t1) == true);
    CHECK((t == t2) == false);
}

TEST_CASE("OPERATOR!=") {
    Time t{12,12,12};
    Time t1{12,12,12};
    Time t2{};
    CHECK((t != t1) == false);
    CHECK((t != t2) == true);
}

TEST_CASE("OPERATOR++") {
    Time t{12, 40, 50};
    //t++; Doesnt work
    ++t;
    Time t1{12, 40, 51};
    CHECK(t.seconds == t1.seconds);
}

TEST_CASE("OPERATOR--") {
    Time t{12, 40, 50};
    //t--; Doesnt work
    --t;
    Time t1{12, 40, 49};
    CHECK(t.seconds == t1.seconds);
}

TEST_CASE("OPERATOR>") {
    Time t1{12,20,55};
    Time t2{15,35,40};
    CHECK((t1 > t2) == false);
}

TEST_CASE("OPERATOR<") {
    Time t1{12,20,55};
    Time t2{15,35,40};
    CHECK((t1 < t2) == true);
}

TEST_CASE("OPERATOR>=") {
    Time t1{12,20,55};
    Time t2{15,35,40};
    CHECK((t1 >= t2) == false);
    CHECK((t1 >= t1) == true);
}

TEST_CASE("OPERATOR<=") {
    Time t1{12,20,55};
    Time t2{15,35,40};
    CHECK((t1 <= t2) == true);
    CHECK((t1 <= t1) == true);
}

TEST_CASE("OPERATOR<<") {
    Time t{15, 25, 35};
    //std::string s =  operator<<(std::cout, t);
    //CHECK(operator<<(std::cout, t) == "15:25:30");
}

TEST_CASE("OPERATOR>>") {
    
}