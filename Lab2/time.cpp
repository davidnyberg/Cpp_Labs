#include "time.hpp"
#include <iostream>

using namespace std;

/*
Input: time object, and a boolean
true = 24 hour time, false = am/pm
Output: Time formatted as a string
*/
string toString(Time& t, bool b) {
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

//prefix
Time& operator++(Time& t) {
    // check for 60 seconds/mins/hours
    ++t.seconds;
        if (t.seconds > 60) {
        t.seconds = t.seconds - 60;
        ++t.minutes;
        if (t.minutes > 60) {
            t.minutes = t.minutes - 60;
            ++t.hours;
            if (t.hours > 24) {
                t.hours = t.hours - 24;
            }
        } 
    }
    return t;
}

//postfix includes an int 0 to match this function
Time operator++(Time& t, int) {
    Time temp{t.hours, t.minutes, t.seconds};
    ++temp.seconds;
        if (temp.seconds > 60) {
        temp.seconds = temp.seconds - 60;
        ++temp.minutes;
        if (temp.minutes > 60) {
            temp.minutes = temp.minutes - 60;
            ++temp.hours;
            if (temp.hours > 24) {
                temp.hours = temp.hours - 24;
            }
        } 
    }
    return temp;
}

Time& operator--(Time& t) {
    //check if seocnds less than zero
    --t.seconds;
        if (t.seconds < 0) {
        t.seconds = t.seconds + 60;
        --t.minutes;
        if (t.minutes < 0) {
            t.minutes = t.minutes + 60;
            --t.hours;
            if (t.hours < 0) {
                t.hours = t.hours + 24;
            }
        } 
    }
    return t;
}

Time operator--(Time& t, int) {
    Time temp{t.hours, t.minutes, t.seconds};
    --temp.seconds;
        if (temp.seconds < 0) {
        temp.seconds = temp.seconds + 60;
        --temp.minutes;
        if (temp.minutes < 0) {
            temp.minutes = temp.minutes + 60;
            --temp.hours;
            if (temp.hours < 0) {
                temp.hours = temp.hours + 24;
            }
        } 
    }
    return temp;
}

Time operator+(Time const& t1, Time const& t2) {
    Time new_t {t1.hours + t2.hours, t1.minutes + t2.minutes,
                t1.seconds + t2.seconds};

        if (new_t.seconds > 60) {
        new_t.seconds = new_t.seconds - 60;
        ++new_t.minutes;
        if (new_t.minutes > 60) {
            new_t.minutes = new_t.minutes - 60;
            ++new_t.hours;
            if (new_t.hours > 24) {
                new_t.hours = new_t.hours - 24;
            }
        } 
    }
    
    return new_t;
}

Time operator+(Time const& t, int i) {
    Time new_t {t.hours, t.minutes, t.seconds + i};
        if (new_t.seconds > 60) {
        new_t.seconds = new_t.seconds - 60;
        ++new_t.minutes;
        if (new_t.minutes > 60) {
            new_t.minutes = new_t.seconds - 60;
            ++new_t.hours;
            if (new_t.hours > 24) {
                new_t.hours = new_t.hours - 24;
            }
        } 
    }
    return new_t;
}

Time operator-(Time const& t1, Time const& t2) {
    Time new_t {t1.hours - t2.hours, t1.minutes - t2.minutes,
            t1.seconds - t2.seconds};
        if (new_t.seconds < 0) {
        new_t.seconds = new_t.seconds + 60;
        --new_t.minutes;
        if (new_t.minutes < 0) {
            new_t.minutes = new_t.minutes + 60;
            --new_t.hours;
            if (new_t.hours < 0) {
                new_t.hours = new_t.hours + 24;
            }
        } 
    }
    return new_t;
}

Time operator-(Time const& t, int i) {
    Time new_t {t.hours, t.minutes, t.seconds - i};
        if (new_t.seconds < 0) {
        new_t.seconds = new_t.seconds + 60;
        --new_t.minutes;
        if (new_t.minutes < 0) {
            new_t.minutes = new_t.minutes + 60;
            --new_t.hours;
            if (new_t.hours < 0) {
                new_t.hours = new_t.hours + 24;
            }
        } 
    }
    return new_t;
}

bool operator>(Time const& lhs, Time const& rhs) {
    if(lhs.hours == rhs.hours) {
        if(lhs.minutes == rhs.minutes) {
            return lhs.seconds > rhs.seconds;
        } else {
            return lhs.minutes > rhs.minutes;
        }
    } else {
        return lhs.hours > rhs.hours;
    }
}

bool operator<(Time const& lhs, Time const& rhs) {
    //simply check greater than, then negate the result
    return !(lhs > rhs);
}

bool operator>=(Time const& lhs, Time const& rhs)  {
    if(lhs.hours == rhs.hours) {
        if(lhs.minutes == rhs.minutes) {
            return lhs.seconds >= rhs.seconds;
        } else {
            return lhs.minutes >= rhs.minutes;
        }
    } else {
        return lhs.hours >= rhs.hours;
    }
}

bool operator<=(Time const& lhs, Time const& rhs) {
    if (lhs == rhs) {
        return true;
    } 
    return !(lhs >= rhs);
}

bool operator!=(Time const& lhs, Time const& rhs) {
    //return the opposite of == operator
    return !(lhs == rhs);
}

bool operator==(Time const& lhs, Time const& rhs) {
    return lhs.hours == rhs.hours && lhs.minutes == rhs.minutes &&
            lhs.seconds == rhs.seconds;
}

ostream& operator<<(ostream& os, Time const& t) {
    os << to_string(t.hours) + ":" + to_string(t.minutes) + ":" + to_string(t.seconds);
    return os;
}

istream& operator>>(istream& is, Time& t) {
    is >> t.hours >> t.minutes >> t.seconds;
    return is;
}