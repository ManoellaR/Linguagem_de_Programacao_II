#include "GenericElement.hpp" 
#include <vector>

int main(){
    if(NDEBUG) cout << "Enter with a shape configuration file to load:" << endl;
    string path;
    cin >> path;

    
    vector< GenericElement* > myListOfElements;

    for(size_t i=0; i< myListOfElements.size(); i++)
    {   
        cout << myListOfElements.at(i)->ShowInfo() << endl;
    }
    
    return 0;
}
