#ifndef ESTRUTURADADOS_HPP
#define ESTRUTURADADOS_HPP

#define NDEBUG 1 // dev = 1 release = 0

#include <iostream>
#include <vector>

using namespace std;

class EstruturaDados{
protected:
    vector < int > m_estrutura;
public:
    EstruturaDados() : m_estrutura(0) {};
    EstruturaDados(vector <int> array) { m_estrutura = array; };
    ~EstruturaDados(){};
    int GetSize(){ return m_estrutura.size(); };
    void SetValor(int valor){ m_estrutura.push_back(valor); };
    void RemoveFrom(){};
    void ShowEstrutura() {
        for(size_t i=0; i<m_estrutura.size(); i++){
            cout << "posição " << i << " -> " << m_estrutura[i] << endl;
        }
    };
};

class Fila : public EstruturaDados{
private:
    Fila(){};
    ~Fila(){};
public:
    void RemoveFrom(){
        m_estrutura.erase(m_estrutura.begin());
    };
};

class Pilha : public EstruturaDados{
private:
    Pilha(){};
    ~Pilha(){};
public:
    void RemoveFrom(){
        int last = (m_estrutura.size() - 1);
        m_estrutura.erase(m_estrutura.begin() + (last));
    };
};
#endif