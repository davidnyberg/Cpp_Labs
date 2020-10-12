#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.hpp"
#include <iostream>
#include <string>


TEST_CASE("INIT") {
    Time time{};
    CHECK(time.hours == 0);
    CHECK(time.minutes == 0);
    CHECK(time.seconds == 0);
}

TEST_CASE("VALIDATE_TIME") {
    Time t{};
    CHECK(isValid(t) == true);

    Time t1{-1, 30, 30};
    CHECK_FALSE(isValid(t1));
}

TEST_CASE("TO_STRING") {
    Time t{12, 30, 30};
    CHECK(toString(t, true) == "12:30:30");
    CHECK(toString(t, true) == "12:30:30");
    CHECK(toString(t, 0) == "12:30:30 pm");
    Time t1{15, 50, 25};
    CHECK(toString(t1, false) == "03:50:25 pm");
}

TEST_CASE("IS_AM") {
    Time t{15, 1, 1};
    CHECK(isAM(t) == false);
    Time t2{03,30,30};
    CHECK(isAM(t2) == true);
}

TEST_CASE("OPERATOR+") {
  //TODO: Complementary work needed. Initialize your variables.
  //DONE
    Time t{};
    Time new_t = t + 5;
    CHECK(new_t.seconds == 05);
    //check that original t is unchanged
    CHECK(t.seconds == 0);

    Time t2{1,1,1};
    Time t3{5,5,5};
    Time add_res{6, 6, 6};
    CHECK(t2 + t3 == add_res);

    //testing some error handing of > 60 seconds - same logic with all other tests
    Time t4{05, 30, 60};
    Time t5 = t4 + 5;
    CHECK(t5.seconds == 5);
    CHECK(t5.minutes == 31);
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

    Time t5{15,30,0};
    Time res{14, 28, 59};
    CHECK(t5 - t2 == res);
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
    Time t1{12, 40, 50};
    Time res{12, 40, 51};
    Time res2{12, 40, 52};

    Time copy = t++;
    CHECK(copy == t1);
    CHECK_FALSE(t == t1);

    //shows that prefix correctly changes the t object
    ++t;
    CHECK(t == res2);
}

TEST_CASE("OPERATOR--") {
    Time t{12, 40, 50};
    Time res{12, 40, 49};

    Time copy = t--;
    CHECK(copy == Time{12, 40, 50});
    CHECK(t == res);

    //shows that prefix correctly changes the t object
    --t;
    CHECK(t == Time{12, 40, 48});
}

TEST_CASE("OPERATOR>") {
    Time t1{12,20,55};
    Time t2{15,35,40};
    //TODO: Complementary work needed. Insufficient testing, test both
    //values that should return true and values that should return
    //false. In this case, do you for example know that this function
    //not always returns false or that two times that are equal would
    //return true. Your tests should be able to test somebody elses
    //code and make sure that it functions properly. Even if this
    //example is specific, the TODO is general and this issue should
    //be fixed in all occurences.
    //
    //DONE fixed all comparisons
    CHECK((t1 > t2) == false);
    CHECK((t2 > t1) == true);
    CHECK((t1 > t1) == false);
}

TEST_CASE("OPERATOR<") {
    Time t1{12,20,55};
    Time t2{15,35,40};
    CHECK((t1 < t2) == true);
    CHECK((t1 > t2) == false);
    CHECK((t1 < t1) == false);
}

TEST_CASE("OPERATOR>=") {
    Time t1{12,20,55};
    Time t2{15,35,40};
    CHECK((t1 >= t2) == false);
    CHECK((t1 >= t1) == true);
    CHECK((t1 >= t1) == true);
}

TEST_CASE("OPERATOR<=") {
    Time t1{12,20,55};
    Time t2{15,35,40};
    CHECK((t1 <= t2) == true);
    CHECK((t1 <= t1) == true);
    CHECK((t1 <= t1) == true);

}

TEST_CASE("OPERATOR<<") {
    Time t{15, 25, 35};
    std::ostringstream oss{};
    oss << t;
    CHECK(oss.str() == "15:25:35");
}

TEST_CASE("OPERATOR>>") {
    Time t{};
    std::istringstream iss{"15:25:35"};
    iss >> t;
    CHECK(toString(t, true) == "15:25:35");
    CHECK(!iss.fail());
     //TODO: Complementary work needed. How do you know that the fail
     //flag ever is set?
     //DONE
    std::istringstream iss2{"44:75:15"};
    Time t2{};
    iss2 >> t2;
    //check_false because this should not go through!
    CHECK_FALSE(toString(t2, true) == "44:75:15");
    //and the fail flag is set because above
    CHECK(iss2.fail());
}
