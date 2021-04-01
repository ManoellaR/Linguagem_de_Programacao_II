#include "shapes.hpp"
#include <vector>

int main(){
    Shape *a = new Shape();
    Shape2D *b = new Shape2D();
    Triangle *c = new Triangle();

    vector < Shape* > myshapes;

    myshapes.push_back(a);
    myshapes.push_back(b);
    myshapes.push_back(c);

    for(size_t i=0; i<myshapes.size(); i++){
        myshapes.at(i)->ShowMe();
    }

    for(size_t i=0; i<myshapes.size(); i++){
        delete myshapes.at(i);
    }
    
    return 0;
}