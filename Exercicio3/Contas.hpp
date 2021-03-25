#ifndef CONTA_HPP
#define CONTA_HPP

#include "Cliente.hpp"
#include <sstream>

class ContaCorrente{
protected:
    float m_saldo;
    Cliente* m_cliente;

public:
    ContaCorrente() : m_cliente(NULL), m_saldo(0) {};
    ContaCorrente(Cliente *cliente, float valor=0) : m_cliente(cliente), m_saldo(valor) {};
    
    string GetNameCliente() const { return m_cliente->GetName(); };
    float GetSaldo() const { return m_saldo; };

    string toString(){
        stringstream s;
        s.precision(2);
        return s.str();
    }
    void Depositar(float valor){ m_saldo += valor; };
    bool Sacar(float valor){
        if((m_saldo - valor) < 0) return false;
        m_saldo -= valor;
        return true;
    }
    bool Transferir(ContaCorrente *conta, float valor){
        if((m_saldo - valor) < 0) return false;
        conta->Depositar(valor);
        m_saldo -= valor;
        return true;
    }
};

class ContaEspecial : public ContaCorrente{
private:
    float m_limite;
public:
    ContaEspecial() : m_limite(0) {};
    ContaEspecial(Cliente *cliente, float valor=0, float limite=1000) : ContaCorrente(cliente, valor), m_limite(limite) {};
    
    bool Sacar(float valor){
        if(m_saldo-valor < -m_limite) return false;
        
        m_saldo -= valor;
        return true;
    }    
    bool Transferir(ContaCorrente *conta, float valor){
        if((m_saldo - valor) < -m_limite) return false;
        
        conta->Depositar(valor);
        m_saldo-=valor;
        return true;
    }    
};

#endif