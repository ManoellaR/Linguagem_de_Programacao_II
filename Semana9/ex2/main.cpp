#include "base.hpp"

int main(){
    Base b;

    Derived1* d1 = (Derived1*) &b;
    Derived2* d2 = (Derived2*) &b;
    
    b.Call();
    d1->Call();
    d2->Call();

    return 0;
}