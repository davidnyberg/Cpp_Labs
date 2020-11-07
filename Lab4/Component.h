#include <string>

//connections, component, resistor, battery, capacitor
//components are connected by cables,

//struct because aggregate
struct Connection {
    //contain current charge of connection
    double charge{};
};

//on exam: const should always be used when functions do not change the values
class Component {
public:
    Component(std::string name, Connection& a, Connection& b);
    virtual void simulate() = 0;
    virtual void current() = 0;
    double voltage;

    virtual ~Component() = default;
protected:
    //allias every component has a and b
    Connection& a;
    Connection& b;

    std::string name{""};
};

class Battery : public Component {
    Battery(std::string name, double voltage, Connection& a, Connection& b) : Component(name, a , b) , voltage{voltage} {}
private:
    double voltage{};
};

class Resistor : public Component {

private:
    double resistance{};
};

class Capacitor : public Component {

private:
    double farad{};
    double load{};
};