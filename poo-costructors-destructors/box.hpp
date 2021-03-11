#ifndef BOX_HPP
#define Box_HPP

#include <iostream>

using namespace std;

class Box{
private:
    size_t m_width, m_height, m_depth;

public:
    //constructors and destructors
    Box() {};
    Box(size_t w, size_t h, size_t d);
    Box(const Box &b);

    //getters and setters
    void SetDimentions(size_t w, size_t h, size_t d);
    size_t GetWidth() const {return m_width; };
    size_t GetHeight() const {return m_height; };
    size_t GetDepth() const {return m_depth; };
};

#endif