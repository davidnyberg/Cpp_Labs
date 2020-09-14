#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "time.hpp"


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
    //TODO: FIX THIS CASE
    //CHECK(toString(t, 0) == "12:30:30 pm");
    Time t1{15, 50, 25};
    //Need to fix the 0 before the 3 in return
    CHECK(toString(t1, false) == "03:50:25 pm");
}