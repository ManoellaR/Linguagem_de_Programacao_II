#include "dictionary.hpp"

int main(){
    Dictionary mydict;
    if(!mydict.LoadDictionary("d4.txt")){
        cout << "File not found" << endl;
        return 1;
    }

    cout << "Dictionary loaded has " << mydict.GetSize() << " words" << endl;

    mydict.SetWord("banana");

    for(size_t i=0; i<mydict.GetSize(); i++){
        cout << "Index" << i << " -> " << mydict.GetWord(i) << endl;
    }

    return 0;
}