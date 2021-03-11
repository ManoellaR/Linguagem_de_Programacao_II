#include "dictionary.hpp"

int main()
{
    Dictionary mydict;    
    if(!mydict.LoadDictionary("d4.txt"))
    {
        cout << "File not found" << endl;
        return 1;
    }
    
    cout << "Dictionary has been loaded and has " << mydict.GetSize() << " words" << endl;
    

    mydict.SetWord("banana");
    mydict.SetWord("pizza");
    mydict.SetWord("Sunday");
    mydict.SetWord("Morning");    
    //mydict.RemoveWord(115);
    //mydict.RemoveWord(115);
    
    mydict.RemoveWord(115, 116);
    
    
    for(size_t i=0; i<mydict.GetSize(); i++)
    {
        cout << "Index " << i << " -> " << mydict.GetWord(i) << endl;
    }
 

    Dictionary mydict1;    
    mydict1.LoadDictionary("d4.txt");

    Dictionary mydict2;    
    mydict2.LoadDictionary("d4.txt");

    Dictionary mydict3;    
    mydict3.LoadDictionary("d4.txt");

        
    vector< Dictionary* > myListOfDictionaries;
    myListOfDictionaries.push_back(&mydict);
    myListOfDictionaries.push_back(&mydict1);
    myListOfDictionaries.push_back(&mydict2);
    myListOfDictionaries.push_back(&mydict3);
 
    return 0;
}

