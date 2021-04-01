#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <iostream>
#include <vector>

using namespace std;

class Shape{
protected:

public:
    Shape() {};
    ~Shape() {};
    virtual void ShowMe() {cout << "I'm a Shape Class" << endl; };
};

class Shape2D : public Shape{
protected:

public:
    Shape2D() {};
    ~Shape2D() {};
    void ShowMe() {cout << "I'm a Shape2D Class" << endl; };
};

class Triangle : public Shape2D{
protected:

public:
    Triangle() {};
    ~Triangle() {};
    void ShowMe() {cout << "I'm a Triangle Class" << endl; };
};

#endif