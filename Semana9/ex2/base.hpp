#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <vector>

using namespace std;

class Base{
private:
protected:
public:
    Base() {};
    ~Base() {};
    void Call() {cout << "Base" << endl; };
};

class Derived1 : public Base{
private:
protected:
public:
    Derived1() {};
    ~Derived1() {};
    void Call() {cout << "Derived1" << endl; };
};

class Derived2 : public Base{
private:
protected:
public:
    Derived2() {};
    ~Derived2() {};
    void Call() {cout << "Derived2" << endl; };    
};

#endif