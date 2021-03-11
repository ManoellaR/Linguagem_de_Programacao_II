#include "GenericElement.hpp"

int main(){
    GenericElement e1;
    GenericElement e2(int (15));
    GenericElement e3(float (10.3));
    GenericElement e4(double (55.5));
    GenericElement e5(char ('A'));
    GenericElement e6(string ("Ha Ha"));
    

    vector< GenericElement > myListOfElements;
    myListOfElements.push_back(e1);
    myListOfElements.push_back(e2);
    myListOfElements.push_back(e3);
    myListOfElements.push_back(e4);
    myListOfElements.push_back(e5);
    myListOfElements.push_back(e6);

    return 0;
}