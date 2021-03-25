#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>

using namespace std;

class Cliente{
private:
    string m_name;

public:
    Cliente() : m_name("") {};
    Cliente(string name) : m_name(name) {};
    ~Cliente() {};

    string GetName() const { return m_name; };
};

#endif