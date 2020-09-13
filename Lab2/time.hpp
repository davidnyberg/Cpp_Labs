

struct Time {
    int hours{};
    int minutes{};
    int seconds{};
};


Time operator++(Time const& t);
Time operator++(Time const& t, int);
Time operator--(Time const& t);

Time operator+(Time const& t1, Time const& t2);
Time operator-(Time const& t1, Time const& t2);

bool operator>(Time const& lhs, Time const& rhs);
bool operator<(Time const& lhs, Time const& rhs);
bool operator>=(Time const& lhs, Time const& rhs);
bool operator<=(Time const& lhs, Time const& rhs);
bool operator!=(Time const& lhs, Time const& rhs);
bool operator==(Time const& lhs, Time const& rhs);

