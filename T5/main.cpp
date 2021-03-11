#include "GenericElement.hpp" 
#include <vector>

int main()
{
    GenericElement e1;
    GenericElement e2(int(15));
    GenericElement e3(float(10.3));
    GenericElement e4(double(55.5));
    GenericElement e5(char('A'));
    GenericElement e6(string("Ha Ha"));
    GenericElement e7(Point2d(2.5,2.5));
    GenericElement e8(Point3d(10,10,2.5));
    
    vector< GenericElement* > myListOfElements;
    myListOfElements.push_back(&e1);
    myListOfElements.push_back(&e2);
    myListOfElements.push_back(&e3);
    myListOfElements.push_back(&e4);
    myListOfElements.push_back(&e5);
    myListOfElements.push_back(&e6);
    myListOfElements.push_back(&e7);
    myListOfElements.push_back(&e8);
    
    for(size_t i=0; i< myListOfElements.size(); i++)
    {   
        cout << myListOfElements.at(i)->ShowInfo() << endl;
    }
    
    return 0;
}
