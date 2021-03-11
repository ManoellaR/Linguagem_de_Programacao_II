#ifndef GENERIC_HPP
#define GENERIC_HPP

#include <iostream>
#include <vector>

using namespace std;

enum DataType{tnone, tint, tfloat, tdouble, tchar, tstring, tpoint2d, tpoint3d};

class Point2d{
public:
    float m_x, m_y;
    Point2d(float x, float y) : m_x(x), m_y(y) {};
};

class Point3d{
public:
    float m_x, m_y, m_z;
    Point3d(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {};
};

class GenericElement{
private:
    void* m_data;
    DataType m_datatype;

public:
    //GenericElement() : m_data(NULL) {};
    GenericElement(){m_data = NULL; m_datatype = tnone; };
    GenericElement(int v) {m_data = new int(v); m_datatype = tint; };
    GenericElement(float v) {m_data = new float(v); m_datatype = tfloat; };
    GenericElement(double v) {m_data = new double(v); m_datatype = tdouble; };
    GenericElement(char v) {m_data = new char(v); m_datatype = tchar; };
    GenericElement(string v) {m_data = new string(v); m_datatype = tstring; };
    GenericElement(Point2d v) {m_data = new Point2d(v); m_datatype = tpoint2d; }
    GenericElement(Point3d v) {m_data = new Point3d(v); m_datatype = tpoint3d; }

};

#endif