#ifndef CONTA_HPP
#define CONTA_HPP

using namespace std;


class Cliente
{
private:
    size_t m_id;
    string m_name;
    
public:
    Cliente() : m_id(0), m_name("") {};
    Cliente(size_t id, string name) : m_id(id), m_name(name) {};
    ~Cliente(){};
    
    string GetNome() const { return m_name; };
};


#endif
















