#include "conta.hpp"

int main()
{
    Cliente *p1 = new Cliente(1, "Antonio Carlos Sobieranski");
    Cliente *p2 = new Cliente(2, "Joao Pereira");
    Cliente *p3 = new Cliente(3, "Ricardo da Silva");
    Cliente *p4 = new Cliente(4, "Danilo Almeida");
    
    ContaCorrente c1(p1, 1000);
    ContaCorrente c2(p2, 5000);
    ContaCorrente c3(p2, 10000);    
    ContaCorrente c4(p3, 12000);
    ContaEspecial c5(p4, 5000);
    
    
    
    c1 += 1000;
    c5 -= 500;    
    c1 >> c2;
    
    
    cout << "Cliente : " << c1.GetClienteNome() << " -> " << c1.GetSaldo() << endl;
    cout << "Cliente : " << c2.GetClienteNome() << " -> " << c2.GetSaldo() << endl;
    cout << "Cliente : " << c3.GetClienteNome() << " -> " << c3.GetSaldo() << endl;
    cout << "Cliente : " << c4.GetClienteNome() << " -> " << c4.GetSaldo() << endl;
    cout << "Cliente : " << c5.GetClienteNome() << " -> " << c5.GetSaldo() << endl;
    
    
    delete p1;
    delete p2;
    delete p3;
 
    return 0;
}
