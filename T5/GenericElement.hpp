#ifndef GENERIC_HPP
#define GENERIC_HPP

#include "Shapes.hpp"

using namespace std;

enum DataType
{
    tnone,
    tcircle,
    tsquare,
    ttriangle,
    tsphere,
    ttetrahedron,
    tcube,
    tpoint2d,
    tpoint3d
};

class GenericElement
{
private:
    void *m_data;
    DataType m_dataType;

public:
    GenericElement(){};
    GenericElement(Circle v)
    {
        m_data = new Circle(v);
        m_dataType = tcircle;
    };
    GenericElement(Square v)
    {
        m_data = new Square(v);
        m_dataType = tsquare;
    };
    GenericElement(Triangle v)
    {
        m_data = new Triangle(v);
        m_dataType = ttriangle;
    };
    GenericElement(Sphere v)
    {
        m_data = new Sphere(v);
        m_dataType = tsphere;
    };
    GenericElement(Tetrahedron v)
    {
        m_data = new Tetrahedron(v);
        m_dataType = ttetrahedron;
    };
    GenericElement(Cube v)
    {
        m_data = new Cube(v);
        m_dataType = tcube;
    };

    ~GenericElement()
    {
        if (m_dataType == tcircle)
            delete ((Circle *)m_data);
        if (m_dataType == tsquare)
            delete ((Square *)m_data);
        if (m_dataType == ttriangle)
            delete ((Triangle *)m_data);
        if (m_dataType == tsphere)
            delete ((Sphere *)m_data);
        if (m_dataType == ttetrahedron)
            delete ((Tetrahedron *)m_data);
        if (m_dataType == tcube)
            delete ((Cube *)m_data);
        if (NDEBUG)
            cout << "Ow man, I'm dying" << endl;
    };

    string ShowInfo()
    {
        stringstream sst;
        sst << "Object is: " << m_dataType;
        if (m_dataType == tnone)
            sst << " NULL";
        if (m_dataType == tcircle)
            sst << "circle -> " << setprecision(2) << fixed << ((Circle *)m_data)->CalcArea();
        if (m_dataType == tsquare)
            sst << "square -> " << setprecision(2) << fixed << ((Square *)m_data)->CalcArea();
        if (m_dataType == ttriangle)
            sst << "triangle -> " << setprecision(2) << fixed << ((Triangle *)m_data)->CalcArea();
        if (m_dataType == tsphere)
            sst << "sphere -> " << setprecision(2) << fixed << ((Sphere *)m_data)->CalcArea();
        if (m_dataType == ttetrahedron)
            sst << "tetrahedron -> " << setprecision(2) << fixed << ((Tetrahedron *)m_data)->CalcArea();
        if (m_dataType == tcube)
            sst << "cube -> " << setprecision(2) << fixed << ((Cube *)m_data)->CalcArea();

        return sst.str();
    };
};

#endif
