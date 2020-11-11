#include <string>
#include <iostream>
//TODO: ADD HEADER GAURDS

//struct because aggregate
struct Connection {
    //contain current charge of connection
    double charge{};
};

class Component {
public:
    Component(std::string name, Connection& a, Connection& b);
    virtual void simulate() const = 0;
    virtual void current() = 0;
    virtual ~Component() = default;
protected:
    //allias every component has a and b
    Connection& a;
    Connection& b;
    std::string name{""};
};

class Battery : public Component {
public:
    Battery(std::string name, double voltage, Connection& a, Connection& b);// : Component(name, a , b), voltage{voltage} {}

    void simulate() const override;
    void current() override;

private:
    //voltage over a component is measured by taking the difference between each terminal.
    double voltage{};
};



class Resistor : public Component {
public:
    Resistor(std::string name, double resistance, Connection& a, Connection& b);// : Component(name, a, b), resistance{resistance} {}
    void simulate() const override {
        std::cout << "resistor simulate" << std::endl;
    }
    void current() override {
        std::cout << "current resisitor" << std::endl;
    }
private:
    double resistance{};
};




class Capacitor : public Component {
public:
    void simulate() const override {
        std::cout << "capacitor simulate" << std::endl;
    }
private:
    double farad{};
    double load{};
};