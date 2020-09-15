#include <string>

struct Time {
    int hours{};
    int minutes{};
    int seconds{};
};

std::string toString(Time & t, bool b);
bool isValid(Time const& t);
bool isAM(Time const& t);

Time& operator++(Time& t);
Time operator++(Time& t, int);
Time& operator--(Time& t);
Time operator--(Time& t, int);

Time operator+(Time const& t1, Time const& t2);
Time operator+(Time const& t, int i);
Time operator-(Time const& t1, Time const& t2);
Time operator-(Time const& t, int i);

bool operator>(Time const& lhs, Time const& rhs);
bool operator<(Time const& lhs, Time const& rhs);
bool operator>=(Time const& lhs, Time const& rhs);
bool operator<=(Time const& lhs, Time const& rhs);
bool operator!=(Time const& lhs, Time const& rhs);
bool operator==(Time const& lhs, Time const& rhs);


