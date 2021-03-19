#include "Shapes.hpp"

Triangle::Triangle(Point2d p1, Point2d p2, Point2d p3){
    m_e3 = sqrt((p1.m_x - p2.m_x)*(p1.m_x - p2.m_x) + (p1.m_y - p2.m_y)*(p1.m_y - p2.m_y));
    m_e2 = sqrt((p1.m_x - p3.m_x)*(p1.m_x - p3.m_x) + (p1.m_y - p3.m_y)*(p1.m_y - p3.m_y));
    m_e1 = sqrt((p2.m_x - p3.m_x)*(p2.m_x - p3.m_x) + (p2.m_y - p3.m_y)*(p2.m_y - p3.m_y));
}

float Triangle::CalcArea(){
    float s = (m_e1 + m_e2 + m_e3)/2;
    float A = sqrt(s*(s-m_e1)*(s-m_e2)*(s-m_e3));

    return A;
}

float Tetrahedron::CalcArea(){
    float m_e1, m_e2, m_e3, m_e4, m_e5, m_e6, s1, s2, s3, A1, A2, A3;
    
    m_e3 = sqrt((m_p1.m_x - m_p2.m_x)*(m_p1.m_x - m_p2.m_x) + (m_p1.m_y - m_p2.m_y)*(m_p1.m_y - m_p2.m_y));
    m_e2 = sqrt((m_p1.m_x - m_p3.m_x)*(m_p1.m_x - m_p3.m_x) + (m_p1.m_y - m_p3.m_y)*(m_p1.m_y - m_p3.m_y));
    m_e1 = sqrt((m_p2.m_x - m_p3.m_x)*(m_p2.m_x - m_p3.m_x) + (m_p2.m_y - m_p3.m_y)*(m_p2.m_y - m_p3.m_y));
    m_e4 = sqrt((m_p1.m_x - m_p4.m_x)*(m_p1.m_x - m_p4.m_x) + (m_p1.m_y - m_p4.m_y)*(m_p1.m_y - m_p4.m_y));
    m_e5 = sqrt((m_p2.m_x - m_p4.m_x)*(m_p2.m_x - m_p4.m_x) + (m_p2.m_y - m_p4.m_y)*(m_p2.m_y - m_p4.m_y));
    m_e6 = sqrt((m_p3.m_x - m_p4.m_x)*(m_p3.m_x - m_p4.m_x) + (m_p3.m_y - m_p4.m_y)*(m_p3.m_y - m_p4.m_y));

    s1 = (m_e1 + m_e2 + m_e3)/2;
    A1 = sqrt(s1*(s1-m_e1)*(s1-m_e2)*(s1-m_e3));
    s2 = (m_e3 + m_e4 + m_e5)/2;
    A2 = sqrt(s2*(s2-m_e3)*(s2-m_e4)*(s2-m_e5));
    s3 = (m_e1 + m_e5 + m_e6)/2;
    A3 = sqrt(s3*(s3-m_e1)*(s3-m_e5)*(s3-m_e6));

    return (A1 + A2 + A3);
}