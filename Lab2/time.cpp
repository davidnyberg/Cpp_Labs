#include "time.hpp"
#include <iostream>
//TODO: Complementary work needed. 2-7. Include every library required
//by the code written in each file. If e.g. string is used in the .h
//file then include it here and if it is also used in the .cc file,
//include it there as well.

using namespace std;

/*
Input: time object, and a boolean
true = 24 hour time, false = am/pm
Output: Time formatted as a string
*/
string toString(Time const& t, bool b) {
    if (b) {
        //format: "14:21:23"

      //TODO: Complementary work needed. Simplify by only having the
      //necessary parts in the if-statements.
        if(t.hours < 10){
            return "0" + to_string(t.hours) + ":" + to_string(t.minutes) +
                   ":" + to_string(t.seconds);
        }else{
            return to_string(t.hours) + ":" + to_string(t.minutes) +
                   ":" + to_string(t.seconds);
        }
    } else {
        //format: "02:30:21 am"
        // add 0 before for nice format

        if (t.hours > 12) {
            if(t.hours - 12 < 10){
                return "0" + to_string(t.hours - 12) + ":" + to_string(t.minutes) +
                       ":" + to_string(t.seconds) + " pm";
            }
            return to_string(t.hours - 12) + ":" + to_string(t.minutes) + 
                ":" + to_string(t.seconds) + " pm";
        } else if(t.hours == 12) {
            return to_string(t.hours) + ":" + to_string(t.minutes) + 
                ":" + to_string(t.seconds) + " pm";
        } else {
            if(t.hours < 10){
                return "0" + to_string(t.hours - 12) + ":" + to_string(t.minutes) +
                       ":" + to_string(t.seconds) + " pm";
            }
            return to_string(t.hours) + ":" + to_string(t.minutes) +
                ":" + to_string(t.seconds) + " am";
        }
    }
}

bool isValid(Time const& t) {
//Comment. You can return the value from the expression.
    return (t.hours <= 23 && t.hours >= 0 &&
        t.minutes <= 59 && t.minutes >= 0 &&
        t.seconds <= 59 && t.seconds >= 0); 
}

bool isAM(Time const& t) {
    if (t.hours < 12) {
        return true;
    }
    return false;
}

//prefix
Time& operator++(Time& t) {
    // check for 60 seconds/mins/ 24hours
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
    ++t;
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
    --t;
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
//TODO: Complementary work needed. This doesn't work for additions of
//say 120 seconds. Use already implemented functions instead.
//DONE, loop i times with increment operator
Time operator+(Time const& t, int i) {
    int j{0};
    Time new_t {t.hours, t.minutes, t.seconds};
    while(j < i){
        ++new_t;
        ++j;
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
    if (lhs == rhs){
        return false;
    }
    return !(lhs > rhs);
}

bool operator>=(Time const& lhs, Time const& rhs)  {
  //TODO: Complementary work needed. Use existing functions. You only
  //have to implement two functions maximum, the rest can be written
  //using these two.
  //DONE now using > and < in the >= and <= operations
    if (lhs == rhs || lhs > rhs){
        return true;
    } else
    return false;
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
  //TODO: Complementary work needed. Use the time to_string instead.
    //DONE
    os << toString(t, true);
    return os;
}

istream& operator>>(istream& is, Time& t) {
    //no error checking here - assuming correct input as stated in assigment
    char colon{};
      //TODO: Complementary work needed. This will assign the time 
   //variable an incorrect value and then the fail flag will be 
   //set. If the time value isn't correct, the fail flag should be set 
   //and the value should not be assigned to the variable. 
   //DONE
    Time tmp{};

    is >> tmp.hours >> colon >> tmp.minutes >> colon >> tmp.seconds;
    //if the new time object is not valid - set the failbit flag
    if (!isValid(tmp)) {
        is.setstate(ios_base::failbit);
    } else {
        //if valid set the tmp time object equal to the reference to t from parameter
        t = tmp;
    }
    return is;
}

