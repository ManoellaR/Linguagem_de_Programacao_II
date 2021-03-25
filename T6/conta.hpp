#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include "cliente.hpp"

class ContaCorrente
{
protected:
    float m_saldo;
    Cliente *m_cliente;
    
public:
    ContaCorrente() : m_cliente(NULL), m_saldo(0) {};
    ContaCorrente(Cliente *cliente, float valor=0) : m_cliente(cliente), m_saldo(valor) {};
    
    float GetSaldo() const { return m_saldo; };
    string GetClienteNome() const { 
        return m_cliente->GetNome();
    };
    
    void Depositar(float valor) { m_saldo += valor; }    
    bool Sacar(float valor) {
        if(m_saldo-valor < 0) return false;
        
        m_saldo -= valor;
        return true;
    }
    
    bool Transferir(ContaCorrente *d, float valor) {
        if(m_saldo-valor < 0) return false;
        
        d->Depositar(valor);
        m_saldo-=valor;
        return true;
    }
    
    void operator+= (float valor)
    {
        Depositar(valor);
    };
    
    void operator-= (float valor)
    {
        Sacar(valor);
    }
    
    bool operator>> (ContaCorrente& c)
    {
        if(!m_saldo) return false;
        
        c.Depositar(m_saldo);
        m_saldo = 0;
        
        return true;
    }
};

class ContaEspecial : public ContaCorrente
{
private:
    float m_limite;
public:
    ContaEspecial() : m_limite(0) {};
    ContaEspecial(Cliente *cliente, float valor=0, float limite=1000) : ContaCorrente(cliente, valor), m_limite(limite) {};
    
    bool Sacar(float valor) {
        if(m_saldo-valor < -m_limite) return false;
        
        m_saldo -= valor;
        return true;
    }    
    
    bool Transferir(ContaCorrente *d, float valor) {
        if(m_saldo-valor < -m_limite) return false;
        
        d->Depositar(valor);
        m_saldo-=valor;
        return true;
    }    
};

#endif
