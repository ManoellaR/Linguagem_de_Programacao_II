#ifndef GENERIC_HPP
#define GENERIC_HPP

#include <iostream>
#include <sstream>

using namespace std;

enum DataType {tnone, tint, tfloat, tdouble, tchar, tstring, tpoint2d, tpoint3d};

class Point2d
{
public:
    float m_x, m_y;
    Point2d(float x, float y) : m_x(x), m_y(y) {};
};

class Point3d
{
public:
    float m_x, m_y, m_z;
    Point3d(float x, float y, float z) : m_x(x), m_y(y), m_z(z) {};
};


class GenericElement
{
private:
    void* m_data;
    DataType m_dataType;
    
public:
    GenericElement()            { m_data = NULL;           m_dataType=tnone; };
    GenericElement(int v)       { m_data = new int(v);     m_dataType=tint; };
    GenericElement(float v)     { m_data = new float(v);   m_dataType=tfloat; };
    GenericElement(double v)    { m_data = new double(v);  m_dataType=tdouble; };
    GenericElement(char v)      { m_data = new char(v);    m_dataType=tchar; };
    GenericElement(string v)    { m_data = new string(v);  m_dataType=tstring; };
    GenericElement(Point2d v)   { m_data = new Point2d(v); m_dataType=tpoint2d; };
    GenericElement(Point3d v)   { m_data = new Point3d(v); m_dataType=tpoint3d; };
    
    ~GenericElement() {
        cout << "Ow man, I'm dying" << endl;
    };
    
        
    string ShowInfo() {
        stringstream sst;
        sst << "Datatype is: " << m_dataType;
        if(m_dataType == tnone)   sst << " -> NULL";
        if(m_dataType == tint)    sst << " -> " << *((int*) m_data);
        if(m_dataType == tfloat)  sst << " -> " << *((float*) m_data);
        if(m_dataType == tdouble) sst << " -> " << *((double*) m_data);
        if(m_dataType == tchar)   sst << " -> " << *((char*) m_data);
        if(m_dataType == tstring) sst << " -> " << *((string*) m_data);
        if(m_dataType == tpoint2d) sst << " -> " << ((Point2d*) m_data)->m_x << "-" << ((Point2d*) m_data)->m_y;
        if(m_dataType == tpoint3d) sst << " -> " << ((Point3d*) m_data)->m_x << "-" << ((Point3d*) m_data)->m_y << "-" << ((Point3d*) m_data)->m_z;
        
        return sst.str();
    };
};


#endif
