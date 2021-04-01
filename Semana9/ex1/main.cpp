#include "shapes.hpp"

int main(){
    Shape *a = new Shape();
    Shape2D *b = new Shape2D();
    Triangle *c = new Triangle();

    a->ShowMe();
    b->ShowMe();
    c->ShowMe();

    delete a;
    delete b;
    delete c;
    
    return 0;
}