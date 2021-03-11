#include "box.hpp"

void Box::SetDimentions(size_t w, size_t h, size_t d){
    m_width = w;
    m_height = h;
    m_depth = d;
}

Box::Box(size_t w, size_t h, size_t d){
    m_width = w;
    m_height = h;
    m_depth = d;
}

Box::Box(const Box &b){
    m_width = b.m_width+5;
    m_height = b.m_height+5;
    m_depth = b.m_depth+5;
}