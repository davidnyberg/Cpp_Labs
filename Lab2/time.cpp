#include "time.hpp"

using namespace std;

/*
Input: time object, and a boolean
true = 24 hour time, false = am/pm
Output: Time formatted as a string
*/
std::string toString(Time & t, bool b) {
    if (b) {
        //format: "14:21:23"
        return to_string(t.hours) + ":" + to_string(t.minutes) + 
                ":" + to_string(t.seconds);
    } else {
        //format: "02:30:21 am"
        if (t.hours > 12) {
            return to_string(t.hours - 12) + ":" + to_string(t.minutes) + 
                ":" + to_string(t.seconds) + " pm";
        } else {
            return to_string(t.hours) + ":" + to_string(t.minutes) + 
                ":" + to_string(t.seconds) + " am";
        }
    }
}

bool isValid(Time const& t) {

    if (t.hours <= 23 && t.hours >= 0 &&
        t.minutes <= 59 && t.minutes >= 0 &&
        t.seconds <= 59 && t.seconds >= 0) {
            return true;
        }
        else {
            return false;
        }
}

Time operator++(Time const& t) {

}

Time operator++(Time const& t, int) {

}

Time operator--(Time const& t) {

}

Time operator+(Time const& t1, Time const& t2) {

}

Time operator-(Time const& t1, Time const& t2) {

}

bool operator>(Time const& lhs, Time const& rhs) {

}

bool operator<(Time const& lhs, Time const& rhs) {

}

bool operator>=(Time const& lhs, Time const& rhs) {

}

bool operator<=(Time const& lhs, Time const& rhs) {

}

bool operator!=(Time const& lhs, Time const& rhs) {

}

bool operator==(Time const& lhs, Time const& rhs) {

}