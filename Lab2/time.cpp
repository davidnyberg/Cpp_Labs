#include "time.hpp"

using namespace std;

/*
Input: time object, and a boolean
true = 24 hour time, false = am/pm
Output: Time formatted as a string
*/
string toString(Time & t, bool b) {
    if (b) {
        //format: "14:21:23"
        return to_string(t.hours) + ":" + to_string(t.minutes) + 
                ":" + to_string(t.seconds);
    } else {
        //format: "02:30:21 am"
        if (t.hours > 12) {
            return to_string(t.hours - 12) + ":" + to_string(t.minutes) + 
                ":" + to_string(t.seconds) + " pm";
        } else if(t.hours == 12) {
            return to_string(t.hours) + ":" + to_string(t.minutes) + 
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

bool isAM(Time const& t) {
    if (t.hours < 12) {
        return true;
    }
    return false;
}

Time operator++(Time const& t) {

}

Time operator++(Time const& t, int) {

}

Time operator--(Time const& t) {

}

Time operator--(Time const& t, int) {

}

Time operator+(Time const& t1, Time const& t2) {
    Time new_t {t1.hours + t2.hours, t1.minutes + t2.minutes,
                t1.seconds + t2.seconds};
    return new_t;
}

Time operator+(Time const& t, int i) {
    Time new_t {t.hours, t.minutes, t.seconds + i};
    return new_t;
}

Time operator-(Time const& t1, Time const& t2) {
    Time new_t {t1.hours - t2.hours, t1.minutes - t2.minutes,
            t1.seconds - t2.seconds};
    return new_t;
}

Time operator-(Time const& t, int i) {
    Time new_t {t.hours, t.minutes, t.seconds - i};
    return new_t;
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
    //return the opposite of == operator
    return !(lhs == rhs);
}

bool operator==(Time const& lhs, Time const& rhs) {
    return lhs.hours == rhs.hours && lhs.minutes == rhs.minutes &&
            lhs.seconds == rhs.seconds;
}