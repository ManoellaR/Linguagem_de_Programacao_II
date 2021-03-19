#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <math.h>

#include "GenericElement.hpp"

using namespace std;

#define NDEBUG 1 // dev = 1 release = 0

class Point2d{
public:
    float m_x, m_y;
    Point2d() : m_x(0), m_y(0) {};
    Point2d(float x, float y) : m_x(x), m_y(y) {};
};

class Point3d{
public:
    float m_x, m_y, m_z;
    Point3d() : m_x(0), m_y(0), m_z(0) {};
    Point3d(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {};
};

class Circle{
private:
    float m_ratio;

public:
    //Constructors
    Circle() : m_ratio(0) {};
    Circle(float x) : m_ratio(x) {};
    //Calcular a area
    float CalcArea() const { return (M_PI*m_ratio*m_ratio); };
};

class Square{
private:
    float m_edge;

public:
    //Constructors
    Square() : m_edge(0) {};
    Square(float x) : m_edge(x) {};
    //Calcular a area
    float CalcArea() const { return (m_edge*m_edge); };

};

class Triangle{
private:
    float m_e1, m_e2,m_e3;

public:
    //Constructors
    Triangle() : m_e1(0), m_e2(0), m_e3(0) {};
    Triangle(Point2d p1, Point2d p2, Point2d p3) {};
    Triangle(float e1, float e2, float e3) : m_e1(e1), m_e2(e2), m_e3(e3) {};
    //Calcular a area
    float CalcArea(); 

};

class Sphere{
private:
    float m_ratio;

public:
    //Constructors
    Sphere() : m_ratio(0) {};
    Sphere(float x) : m_ratio(x) {};
    //Calcular a area
    float CalcArea() const { return (4*M_PI*m_ratio*m_ratio); };

};

class Tetrahedron{
private:
    Point3d m_p1, m_p2, m_p3, m_p4;

public:
    //Constructors
    Tetrahedron(){ m_p1=m_p2=m_p3=m_p4=Point3d(0,0,0); };
    Tetrahedron(Point3d p1, Point3d p2, Point3d p3, Point3d p4) : m_p1(p1), m_p2(p2), m_p3(p3), m_p4(p4) {};
    //Calcular a area
    float CalcArea();

};

class Cube{
private:
    float m_edge;

public:
    //Constructors
    Cube() : m_edge(0) {};
    Cube(float x) : m_edge(x) {};
    //Calcular a area
    float CalcArea() const { return (6*m_edge*m_edge); };

};

#endif