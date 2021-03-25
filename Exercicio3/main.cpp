#include "Contas.hpp"
#include "Contas.hpp"

int main(){
    Cliente *clienteA = new Cliente("A");
    Cliente *clienteB = new Cliente("B");
    Cliente *clienteC = new Cliente("C");

    ContaCorrente contaA(clienteA, 5000);
    ContaCorrente contaB(clienteB, 10000);
    ContaEspecial contaC(clienteC, 15000);

    

    delete clienteA;
    delete clienteB;
    delete clienteC;

    return 0;
}