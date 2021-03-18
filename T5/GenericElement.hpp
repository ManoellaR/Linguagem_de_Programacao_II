#ifndef GENERIC_HPP
#define GENERIC_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

#define NDEBUG 1 // dev = 1 release = 0

enum DataType {tnone, tcircle, tsquare, ttriangle, tsphere, ttetrahedron, tcube, tpoint2d, tpoint3d};

class Circle{
private:
    int m_ratio;

public:
    //Constructors
    Circle(){};
    Circle(int x) : m_ratio(x) {};
    //Calcular a area
    float CalcArea(){ return (M_PI*m_ratio*m_ratio); };

};

class Square{
private:
    int m_edge;

public:
    //Constructors
    Square(){};
    Square(int x) : m_edge(x) {};
    //Calcular a area
    float CalcArea(){ return (m_edge*m_edge); };

};

class Triangle{
private:
    Point2d m_p1, m_p2, m_p3;
    float m_e1, m_e2,m_e3;

public:
    //Constructors
    Triangle(){};
    Triangle(Point2d p1, Point2d p2, Point2d p3){};
    Triangle(float e1, float e2, float e3) : m_e1(e1), m_e2(e2), m_e3(e3) {};
    //Calcular a area
    float CalcArea(); 

};

class Sphere{
private:
    int m_ratio;

public:
    //Constructors
    Sphere(){};
    Sphere(int x) : m_ratio(x) {};
    //Calcular a area
    float CalcArea(){return (4*M_PI*m_ratio*m_ratio*m_ratio); };

};

class Tetrahedron{
private:
    Point3d m_p1, m_p2, m_p3, m_p4;

public:
    //Constructors
    Tetrahedron(){};
    Tetrahedron(Point3d p1, Point3d p2, Point3d p3) : m_p1(p1), m_p2(p2), m_p3(p3) {};
    //Calcular a area
    float CalcArea();

};

class Cube{
private:
    int m_edge;

public:
    //Constructors
    Cube(){};
    Cube(int x) : m_edge(x) {};
    //Calcular a area
    float CalcArea(){ return (6*m_edge*m_edge); };

};

class Point2d{
public:
    float m_x, m_y;
    Point2d(){};
    Point2d(float x, float y) : m_x(x), m_y(y) {};
};

class Point3d{
public:
    float m_x, m_y, m_z;
    Point3d(){};
    Point3d(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {};
};


class GenericElement{
private:
    void* m_data;
    DataType m_dataType;
    
public:
    GenericElement(Circle v)      { m_data = new Circle(v);      m_dataType=tcircle; };
    GenericElement(Square v)      { m_data = new Square(v);      m_dataType=tsquare; };
    GenericElement(Triangle v)    { m_data = new Triangle(v);    m_dataType=ttriangle; };
    GenericElement(Sphere v)      { m_data = new Sphere(v);      m_dataType=tsphere; };
    GenericElement(Tetrahedron v) { m_data = new Tetrahedron(v); m_dataType=ttetrahedron; };
    GenericElement(Cube v)        { m_data = new Cube(v);        m_dataType=tcube; };

    ~GenericElement() {
        cout << "Ow man, I'm dying" << endl;
    };

          
    string ShowInfo() {
        stringstream sst;
        sst << "Datatype is: " << m_dataType;
        if(m_dataType == tnone) sst << " -> NULL";
        if(m_dataType == tcircle) sst << "circle -> " << setprecision(2) << fixed << ((Circle *)m_data)->CalcArea();
        if(m_dataType == tsquare) sst << "square -> " << setprecision(2) << fixed << ((Square *)m_data)->CalcArea();
        if(m_dataType == ttriangle) sst << "triangle -> " << setprecision(2) << fixed << ((Triangle *)m_data)->CalcArea();
        if(m_dataType == tsphere) sst << "sphere -> " << setprecision(2) << fixed << ((Sphere *)m_data)->CalcArea();
        if(m_dataType == ttetrahedron) sst << "tetrahedron -> " << setprecision(2) << fixed << ((Tetrahedron *)m_data)->CalcArea();
        if(m_dataType == tcube) sst << "cube -> " << setprecision(2) << fixed << ((Cube *)m_data)->CalcArea();

        return sst.str();
    };
};


#endif
